#include "DataProc.h"
#include "../HAL/HAL.h"

static void onTimer(Account* account)
{
    // static bool lastStatus = false;

    // HAL::PowerPD_Info_t power;
    // HAL::PowerPD_GetInfo(&power);
    // if (power.isCharging != lastStatus)
    // {
    //     lastStatus = power.isCharging;
    // }
}

static int onEvent(Account* account, Account::EventParam_t* param)
{
    // if (param->event == Account::EVENT_TIMER)
    // {
    //     onTimer(account);
    //     return 0;
    // }

    // if (param->event != Account::EVENT_SUB_PULL)
    // {
    //     return Account::ERROR_UNSUPPORTED_REQUEST;
    // }

    // if (param->size != sizeof(HAL::PowerPD_Info_t))
    // {
    //     return Account::ERROR_SIZE_MISMATCH;
    // }

    // HAL::PowerPD_Info_t powerInfo;
    // HAL::PowerPD_GetInfo(&powerInfo);

    // memcpy(param->data_p, &powerInfo, param->size);

    return 0;
}

DATA_PROC_INIT_DEF(PowerPD)
{
    account->SetEventCallback(onEvent);
    account->SetTimerPeriod(500);
}
