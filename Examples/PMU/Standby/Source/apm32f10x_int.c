/*!
 * @file        apm32f10x_int.c
 *
 * @brief      Main Interrupt Service Routines
 *
 * @version     V1.0.2
 *
 * @date        2022-01-05
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#include "main.h"
#include "apm32f10x_int.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup INT_Driver INT Driver
  @{
*/

/** @addtogroup INT_Fuctions Fuctions
  @{
*/

/*!
 * @brief   This function handles NMI exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void NMI_Handler(void)
{
}

/*!
 * @brief   This function handles Hard Fault exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void HardFault_Handler(void)
{
    /** Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief   This function handles Memory Manage exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void MemManage_Handler(void)
{
    /** Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief   This function handles Bus Fault exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void BusFault_Handler(void)
{
    /** Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief   This function handles Usage Fault exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void UsageFault_Handler(void)
{
    /** Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief   This function handles SVCall exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void SVC_Handler(void)
{
}

/*!
 * @brief   This function handles Debug Monitor exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void DebugMon_Handler(void)
{
}

/*!
 * @brief   This function handles PendSV_Handler exception
 *
 * @param   None
 *
 * @retval  None
 *
 */
void PendSV_Handler(void)
{
}

/*!
 * @brief   This function handles SysTick Handler
 *
 * @param   None
 *
 * @retval  None
 *
 */
void SysTick_Handler(void)
{
    APM_MINI_LEDToggle(LED2);
}

/*!
 * @brief   This function handles External lines 1 request
 *
 * @param   None
 *
 * @retval  None
 *
 */
void EINT1_IRQHandler(void)
{
    if(EINT_ReadIntFlag(KEY1_BUTTON_EINT_LINE) != RESET)
    {
        EINT_ClearIntFlag(KEY1_BUTTON_EINT_LINE);
        APM_MINI_LEDOn(LED2);

        RTC_ClearStatusFlag(RTC_FLAG_SEC);
        while(RTC_ReadStatusFlag(RTC_FLAG_SEC) == RESET);

        RTC_ConfigAlarm(RTC_ReadCounter()+ 3);
        RTC_WaitForLastTask();

        PMU_EnterSTANDBYMode();
    }
}

/**@} end of group INT_Fuctions*/
/**@} end of group INT_Driver*/
/**@} end of group Peripherals_Library*/
