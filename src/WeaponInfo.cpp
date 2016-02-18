/* =========================================

		FCNPC - Fully Controllable NPC
			----------------------

	- File: WeaponInfo.cpp
	- Author(s): OrMisicL, ziggi

  =========================================*/

#include "Main.h"

const CWeaponInfo::SWeaponInfo CWeaponInfo::m_sDefaultWeaponInfo[MAX_WEAPONS] = {
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_BRASSKNUCKLE (1)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_GOLFCLUK (2)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_NITESTICE (3)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_KNIFT (4)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_BAL (5)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_SHOVEK (6)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_POOLSTICA (7)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_KATANW (8)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   30,  50}, // WEAPON_CHAINSAO (9)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_DILD (10)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_DILDO2 (11)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_VIBRATOR (12)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_VIBRATOR2 (13)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_FLOWER (14)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   250, 50}, // WEAPON_CANE (15)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   500, 50}, // WEAPON_GRENADE (16)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   500, 50}, // WEAPON_TEARGAS (17)
	{WEAPON_TYPE_MELEE,   5.0f,  0,   500, 50}, // WEAPON_MOLTOV (18)
	{WEAPON_TYPE_NONE,    0.0f,  0,   0,   0}, // nothing (19)
	{WEAPON_TYPE_NONE,    0.0f,  0,   0,   0}, // nothing (20)
	{WEAPON_TYPE_NONE,    0.0f,  0,   0,   0}, // nothing (21)
	{WEAPON_TYPE_SHOOT,   20.0f, 17,  160, 2000}, // WEAPON_COLT45 (22)
	{WEAPON_TYPE_SHOOT,   20.0f, 17,  120, 2000}, // WEAPON_SILENCED (23)
	{WEAPON_TYPE_SHOOT,   40.0f, 7,   120, 2000}, // WEAPON_DEAGLE (24)
	{WEAPON_TYPE_SHOOT,   30.0f, 1,   800, 2000}, // WEAPON_SHOTGUN (25)
	{WEAPON_TYPE_SHOOT,   30.0f, 2,   120, 2000}, // WEAPON_SAWEDOFF (26)
	{WEAPON_TYPE_SHOOT,   30.0f, 7,   120, 2000}, // WEAPON_SHOTGSPA (27)
	{WEAPON_TYPE_SHOOT,   10.0f, 50,  50,  2000}, // WEAPON_UZI (28)
	{WEAPON_TYPE_SHOOT,   10.0f, 30,  90,  2000}, // WEAPON_MP5 (29)
	{WEAPON_TYPE_SHOOT,   20.0f, 30,  90,  2000}, // WEAPON_AK47 (30)
	{WEAPON_TYPE_SHOOT,   20.0f, 50,  90,  2000}, // WEAPON_M4 (31)
	{WEAPON_TYPE_SHOOT,   10.0f, 50,  70,  2000}, // WEAPON_TEC9 (32)
	{WEAPON_TYPE_SHOOT,   60.0f, 1,   800, 1000}, // WEAPON_RIFLE (33)
	{WEAPON_TYPE_SHOOT,   40.0f, 1,   900, 1000}, // WEAPON_SNIPER (34)
	{WEAPON_TYPE_ROCKET,  5.0f,  1,   500, 1000}, // WEAPON_ROCKETLAUNCHER (35)
	{WEAPON_TYPE_ROCKET,  5.0f,  1,   500, 1000}, // WEAPON_HEATSEEKER (36)
	{WEAPON_TYPE_SPRAY,   5.0f,  500, 500, 1000}, // WEAPON_FLAMETHROWER (37)
	{WEAPON_TYPE_SHOOT,   10.0f, 500, 20,  1000}, // WEAPON_MINIGUN (38)
	{WEAPON_TYPE_MELEE,   5.0f,  1,   500, 1000}, // WEAPON_SATCHEL (39)
	{WEAPON_TYPE_MELEE,   5.0f,  1,   500, 2000}, // WEAPON_BOMB (40)
	{WEAPON_TYPE_SPRAY,   5.0f,  500, 10,  1000}, // WEAPON_SPRAYCAN (41)
	{WEAPON_TYPE_SPRAY,   5.0f,  500, 10,  1000}, // WEAPON_FIREEXTINGUISHER (42)
	{WEAPON_TYPE_SPECIAL, 0.0f,  1,   500, 500}, // WEAPON_CAMERA (43)
	{WEAPON_TYPE_SPECIAL, 0.0f,  0,   500, 500}, // WEAPON_NIGHTVISION (44)
	{WEAPON_TYPE_SPECIAL, 0.0f,  0,   500, 500}, // WEAPON_INFRARED (45)
	{WEAPON_TYPE_SPECIAL, 0.0f,  1,   500, 500} // WEAPON_PARACHUTE (46)
};

CWeaponInfo::CWeaponInfo()
{
	for (int i = 0; i < (sizeof(m_pWeaponInfo) / sizeof(m_pWeaponInfo[0])); i++) {
		m_pWeaponInfo[i] = new SWeaponInfo(*GetDefaultInfo(i));
	}
}

bool CWeaponInfo::SetDefaultInfo(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId] = GetDefaultInfo(iWeaponId);
	return true;
}

CWeaponInfo::SWeaponInfo *CWeaponInfo::GetDefaultInfo(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return NULL;
	}

	return &(CWeaponInfo::SWeaponInfo)m_sDefaultWeaponInfo[iWeaponId];
}

int CWeaponInfo::GetWeaponType(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return 0.0f;
	}

	return m_pWeaponInfo[iWeaponId]->iType;
}

bool CWeaponInfo::SetWeaponType(int iWeaponId, int iType)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId]->iType = iType;
	return true;
}

float CWeaponInfo::GetWeaponDamage(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return 0.0f;
	}

	return m_pWeaponInfo[iWeaponId]->fDamage;
}

bool CWeaponInfo::SetWeaponDamage(int iWeaponId, float fDamage)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId]->fDamage = fDamage;
	return true;
}

int CWeaponInfo::GetWeaponClipSize(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return -1;
	}

	return m_pWeaponInfo[iWeaponId]->iClipSize;
}

bool CWeaponInfo::SetWeaponClipSize(int iWeaponId, int iClipSize)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId]->iClipSize = iClipSize;
	return true;
}

// The fastest possible gap between weapon shots in milliseconds by oscar-broman
int CWeaponInfo::GetWeaponShootTime(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return -1;
	}

	return m_pWeaponInfo[iWeaponId]->iShootTime;
}

bool CWeaponInfo::SetWeaponShootTime(int iWeaponId, int iShootTime)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId]->iShootTime = iShootTime;
	return true;
}

int CWeaponInfo::GetWeaponReloadTime(int iWeaponId)
{
	if (!IsValidWeapon(iWeaponId)) {
		return -1;
	}

	return m_pWeaponInfo[iWeaponId]->iReloadTime;
}

bool CWeaponInfo::SetWeaponReloadTime(int iWeaponId, int iReloadTime)
{
	if (!IsValidWeapon(iWeaponId)) {
		return false;
	}

	m_pWeaponInfo[iWeaponId]->iReloadTime = iReloadTime;
	return true;
}

bool CWeaponInfo::IsValidWeapon(int iWeaponId)
{
	return iWeaponId > 0 && iWeaponId < MAX_WEAPONS;
}

bool CWeaponInfo::IsDoubleHanded(int iWeaponId)
{
	if (iWeaponId == 22 || iWeaponId == 26 || iWeaponId == 28 || iWeaponId == 32) {
		return true;
	}

	return false;
}
