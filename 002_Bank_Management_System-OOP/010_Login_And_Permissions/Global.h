#pragma once
#include "clsUser.h"
static clsUser CurrentUser = clsUser::GetEmptyUser();
static short LoginTrials = 3;