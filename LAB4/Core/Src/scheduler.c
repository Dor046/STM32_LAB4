/*
 * scheduler.c
 *
 *  Created on: Nov 10, 2025
 *      Author: User
 */

#include "scheduler.h"
#define SCH_TICK_MS 10

sTasks SCH_tasks_G[SCH_MAX_TASKS];
static uint32_t Head_Index = NO_TASK_ID;

void SCH_Init(void) {
    unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
    Head_Index = NO_TASK_ID;
}

unsigned char SCH_Delete_Task(const uint8_t TASK_INDEX) {
    if (SCH_tasks_G[TASK_INDEX].pTask == 0) return 0;
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
    return 1;
}

/* * Hàm thêm tác vụ (Đã sửa đổi để nhận ms)
 * Input: DELAY và PERIOD tính bằng mili-giây (ms)
 */
unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY_MS, uint32_t PERIOD_MS) {
    uint8_t Index = 0;
    uint32_t delay_in_ticks = DELAY_MS / SCH_TICK_MS;
    uint32_t period_in_ticks = PERIOD_MS / SCH_TICK_MS;

    // 1. Tìm vị trí trống trong mảng
    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
        Index++;
    }
    if (Index == SCH_MAX_TASKS) {
        return SCH_MAX_TASKS; // Hết bộ nhớ
    }

    // 2. Gán thông tin cơ bản cho Task mới (DÙNG GIÁ TRỊ ĐÃ QUY ĐỔI)
    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = delay_in_ticks;
    SCH_tasks_G[Index].Period = period_in_ticks;
    SCH_tasks_G[Index].RunMe = 0;

    // 3. Chèn vào danh sách liên kết đã sắp xếp (Delta Delay)

    // Trường hợp danh sách rỗng
    if (Head_Index == NO_TASK_ID) {
        Head_Index = Index;
        SCH_tasks_G[Index].TaskID = NO_TASK_ID;
        return Index;
    }

    // Trường hợp chèn vào ĐẦU danh sách
    if (delay_in_ticks < SCH_tasks_G[Head_Index].Delay) {
        SCH_tasks_G[Head_Index].Delay -= delay_in_ticks;
        SCH_tasks_G[Index].TaskID = Head_Index;
        Head_Index = Index;
        return Index;
    }

    // Trường hợp chèn vào GIỮA hoặc CUỐI danh sách
    uint8_t current = Head_Index;
    uint8_t prev = NO_TASK_ID;

    while (current != NO_TASK_ID) {
        if (delay_in_ticks < SCH_tasks_G[current].Delay) {
            break;
        }
        delay_in_ticks -= SCH_tasks_G[current].Delay;
        prev = current;
        current = SCH_tasks_G[current].TaskID;
    }

    SCH_tasks_G[Index].Delay = delay_in_ticks;
    SCH_tasks_G[Index].TaskID = current;
    SCH_tasks_G[prev].TaskID = Index;

    if (current != NO_TASK_ID) {
        SCH_tasks_G[current].Delay -= delay_in_ticks;
    }

    return Index;
}

void SCH_Update(void) {
    if (Head_Index != NO_TASK_ID) {
        if (SCH_tasks_G[Head_Index].Delay > 0) {
            SCH_tasks_G[Head_Index].Delay--;
        }

        if (SCH_tasks_G[Head_Index].Delay == 0) {
            SCH_tasks_G[Head_Index].RunMe += 1;

            // Nâng cao: Kiểm tra dây chuyền (Chain Check) nếu cần
            uint32_t current_task_id = SCH_tasks_G[Head_Index].TaskID;
            while (current_task_id != NO_TASK_ID) {
                if (SCH_tasks_G[current_task_id].Delay == 0) {
                    SCH_tasks_G[current_task_id].RunMe += 1;
                    current_task_id = SCH_tasks_G[current_task_id].TaskID;
                } else {
                    break;
                }
            }
        }
    }
}

void SCH_Dispatch_Tasks(void) {
    if (Head_Index != NO_TASK_ID) {
        if (SCH_tasks_G[Head_Index].RunMe > 0) {

            // 1. Thực thi tác vụ
            (*SCH_tasks_G[Head_Index].pTask)();
            SCH_tasks_G[Head_Index].RunMe -= 1;

            // 2. Lưu thông tin để nạp lại
            sTasks tempTask = SCH_tasks_G[Head_Index];
            uint8_t oldHead = Head_Index;

            // 3. Xóa khỏi đầu danh sách
            Head_Index = SCH_tasks_G[Head_Index].TaskID;
            SCH_tasks_G[oldHead].pTask = 0; // Giải phóng ô nhớ

            // 4. Nạp lại (QUAN TRỌNG: PHẢI NHÂN NGƯỢC LẠI THÀNH MS)
            if (tempTask.Period > 0) {
                // Vì hàm SCH_Add_Task nhận đầu vào là MS và sẽ chia cho 10
                // Nên ta phải nhân Period (đang là Tick) với 10 để bù trừ.
                // Delay cho lần sau chính là Period của nó.
                SCH_Add_Task(tempTask.pTask,
                             tempTask.Period * SCH_TICK_MS,
                             tempTask.Period * SCH_TICK_MS);
            }
        }
    }
}








