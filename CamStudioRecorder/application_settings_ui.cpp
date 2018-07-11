/**
 * Copyright(C) 2018  Steven Hoving
 *
 * This program is free software : you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include "application_settings_ui.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(application_settings_ui, CDialogEx)

application_settings_ui::application_settings_ui(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_APPLICATION_SETTINGS_UI, pParent)
{

}

application_settings_ui::application_settings_ui(CWnd* pParent, settings_model &model)
    : CDialogEx(IDD_APPLICATION_SETTINGS_UI, pParent)
    , settings_(&model)
{
}

application_settings_ui::~application_settings_ui()
{
}

BOOL application_settings_ui::OnInitDialog()
{

}

void application_settings_ui::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(application_settings_ui, CDialogEx)
END_MESSAGE_MAP()
