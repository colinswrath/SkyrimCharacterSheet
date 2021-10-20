#pragma once
#include "stats/statholder.h"

class StatFiller {
public:
    using ActorValue = RE::ActorValue;
    using Menu = StatsMenuValue;

    static StatFiller* GetSingleton() {
        static StatFiller singleton;
        return std::addressof(singleton);
    }

    std::vector<std::shared_ptr<StatItem>> getData() {
        std::vector<std::shared_ptr<StatItem>> statList = {
            std::make_shared<StatItem>(StatsValue::name, ActorValue::kNone, *Settings::nameString,
                *Settings::nameStringEnding, *Settings::name),
            std::make_shared<StatItem>(StatsValue::race, ActorValue::kNone, *Settings::raceString,
                *Settings::raceStringEnding, *Settings::race),
            std::make_shared<StatItem>(StatsValue::level, ActorValue::kNone, *Settings::levelString,
                *Settings::levelStringEnding, *Settings::level),
            std::make_shared<StatItem>(StatsValue::perkCount, ActorValue::kNone, *Settings::perkCountString,
                *Settings::perkCountStringEnding, *Settings::perkCount),
            std::make_shared<StatItem>(StatsValue::height, ActorValue::kNone, *Settings::heightString,
                *Settings::heightStringEnding, *Settings::height, getStatsMenu(*Settings::heightMenu)),
            std::make_shared<StatItem>(StatsValue::equipedWeight, ActorValue::kNone, *Settings::equipedWeightString,
                *Settings::equipedWeightStringEnding, *Settings::equipedWeight,
                getStatsMenu(*Settings::equipedWeightMenu)),
            std::make_shared<StatItem>(StatsValue::weight, ActorValue::kNone, *Settings::weightString,
                *Settings::weightStringEnding, *Settings::weight, getStatsMenu(*Settings::weightMenu)),
            std::make_shared<StatItem>(StatsValue::armor, ActorValue::kNone, *Settings::armorString,
                *Settings::armorStringEnding, *Settings::armor, getStatsMenu(*Settings::armorMenu)),
            std::make_shared<StatItem>(StatsValue::damage, ActorValue::kNone, *Settings::damageString,
                *Settings::damageStringEnding, *Settings::damage, getStatsMenu(*Settings::damageMenu)),
            std::make_shared<StatItem>(StatsValue::skillTrainingsThisLevel, ActorValue::kNone,
                *Settings::skillTrainingsThisLevelString, *Settings::skillTrainingsThisLevelStringEnding,
                *Settings::skillTrainingsThisLevel, getStatsMenu(*Settings::skillTrainingsThisLevelMenu)),
            std::make_shared<StatItem>(StatsValue::health, ActorValue::kHealth, *Settings::healthString,
                *Settings::healthStringEnding, *Settings::health, getStatsMenu(*Settings::healthMenu)),
            std::make_shared<StatItem>(StatsValue::healthRatePer, ActorValue::kNone, *Settings::healthRateString,
                *Settings::healthRateStringEnding, *Settings::healthRate, getStatsMenu(*Settings::healthRateMenu)),
            std::make_shared<StatItem>(StatsValue::magicka, ActorValue::kMagicka, *Settings::magickaString,
                *Settings::magickaStringEnding, *Settings::magicka, getStatsMenu(*Settings::magickaMenu)),
            std::make_shared<StatItem>(StatsValue::magickaRatePer, ActorValue::kNone, *Settings::magickaRateString,
                *Settings::magickaRateStringEnding, *Settings::magickaRate, getStatsMenu(*Settings::magickaRateMenu)),
            std::make_shared<StatItem>(StatsValue::stamina, ActorValue::kStamina, *Settings::staminaString,
                *Settings::staminaStringEnding, *Settings::stamina, getStatsMenu(*Settings::staminaMenu)),
            std::make_shared<StatItem>(StatsValue::staminaRatePer, ActorValue::kNone, *Settings::staminaRateString,
                *Settings::staminaRateStringEnding, *Settings::staminaRate, getStatsMenu(*Settings::staminaRateMenu)),
            std::make_shared<StatItem>(StatsValue::resistDamage, ActorValue::kDamageResist,
                *Settings::resistDamageString, *Settings::resistDamageStringEnding, *Settings::resistDamage,
                getStatsMenu(*Settings::resistDamageMenu)),
            std::make_shared<StatItem>(StatsValue::resistDisease, ActorValue::kResistDisease,
                *Settings::resistDiseaseString, *Settings::resistDiseaseStringEnding, *Settings::resistDisease,
                getStatsMenu(*Settings::resistDiseaseMenu)),
            std::make_shared<StatItem>(StatsValue::resistPoison, ActorValue::kPoisonResist,
                *Settings::resistPoisonString, *Settings::resistPoisonStringEnding, *Settings::resistPoison,
                getStatsMenu(*Settings::resistPoisonMenu)),
            std::make_shared<StatItem>(StatsValue::resistFire, ActorValue::kResistFire, *Settings::resistFireString,
                *Settings::resistFireStringEnding, *Settings::resistFire, getStatsMenu(*Settings::resistFireMenu)),
            std::make_shared<StatItem>(StatsValue::resistShock, ActorValue::kResistShock, *Settings::resistShockString,
                *Settings::resistShockStringEnding, *Settings::resistShock, getStatsMenu(*Settings::resistShockMenu)),
            std::make_shared<StatItem>(StatsValue::resistFrost, ActorValue::kResistFrost, *Settings::resistFrostString,
                *Settings::resistFrostStringEnding, *Settings::resistFrost, getStatsMenu(*Settings::resistFrostMenu)),
            std::make_shared<StatItem>(StatsValue::resistMagic, ActorValue::kResistMagic, *Settings::resistMagicString,
                *Settings::resistMagicStringEnding, *Settings::resistMagic, getStatsMenu(*Settings::resistMagicMenu)),
            std::make_shared<StatItem>(StatsValue::oneHanded, ActorValue::kOneHanded, *Settings::oneHandedString,
                *Settings::oneHandedStringEnding, *Settings::oneHanded, getStatsMenu(*Settings::oneHandedMenu)),
            std::make_shared<StatItem>(StatsValue::twoHanded, ActorValue::kTwoHanded, *Settings::twoHandedString,
                *Settings::twoHandedStringEnding, *Settings::twoHanded, getStatsMenu(*Settings::twoHandedMenu)),
            std::make_shared<StatItem>(StatsValue::archery, ActorValue::kArchery, *Settings::archeryString,
                *Settings::archeryStringEnding, *Settings::archery, getStatsMenu(*Settings::archeryMenu)),
            std::make_shared<StatItem>(StatsValue::block, ActorValue::kBlock, *Settings::blockString,
                *Settings::blockStringEnding, *Settings::block, getStatsMenu(*Settings::blockMenu)),
            std::make_shared<StatItem>(StatsValue::smithing, ActorValue::kSmithing, *Settings::smithingString,
                *Settings::smithingStringEnding, *Settings::smithing, getStatsMenu(*Settings::smithingMenu)),
            std::make_shared<StatItem>(StatsValue::heavyArmor, ActorValue::kHeavyArmor, *Settings::heavyArmorString,
                *Settings::heavyArmorStringEnding, *Settings::heavyArmor, getStatsMenu(*Settings::heavyArmorMenu)),
            std::make_shared<StatItem>(StatsValue::lightArmor, ActorValue::kLightArmor, *Settings::lightArmorString,
                *Settings::lightArmorStringEnding, *Settings::lightArmor, getStatsMenu(*Settings::lightArmorMenu)),
            std::make_shared<StatItem>(StatsValue::pickpocket, ActorValue::kPickpocket, *Settings::pickpocketString,
                *Settings::pickpocketStringEnding, *Settings::pickpocket, getStatsMenu(*Settings::pickpocketMenu)),
            std::make_shared<StatItem>(StatsValue::lockpicking, ActorValue::kLockpicking, *Settings::lockpickingString,
                *Settings::lockpickingStringEnding, *Settings::lockpicking, getStatsMenu(*Settings::lockpickingMenu)),
            std::make_shared<StatItem>(StatsValue::sneak, ActorValue::kSneak, *Settings::sneakString,
                *Settings::sneakStringEnding, *Settings::sneak, getStatsMenu(*Settings::sneakMenu)),
            std::make_shared<StatItem>(StatsValue::alchemy, ActorValue::kAlchemy, *Settings::alchemyString,
                *Settings::alchemyStringEnding, *Settings::alchemy, getStatsMenu(*Settings::alchemyMenu)),
            std::make_shared<StatItem>(StatsValue::speech, ActorValue::kSpeech, *Settings::speechString,
                *Settings::speechStringEnding, *Settings::speech, getStatsMenu(*Settings::speechMenu)),
            std::make_shared<StatItem>(StatsValue::enchanting, ActorValue::kEnchanting, *Settings::enchantingString,
                *Settings::enchantingStringEnding, *Settings::enchanting, getStatsMenu(*Settings::enchantingMenu)),
            std::make_shared<StatItem>(StatsValue::alteration, ActorValue::kAlteration, *Settings::alterationString,
                *Settings::alterationStringEnding, *Settings::alteration, getStatsMenu(*Settings::alterationMenu)),
            std::make_shared<StatItem>(StatsValue::conjuration, ActorValue::kConjuration, *Settings::conjurationString,
                *Settings::conjurationStringEnding, *Settings::conjuration, getStatsMenu(*Settings::conjurationMenu)),
            std::make_shared<StatItem>(StatsValue::destruction, ActorValue::kDestruction, *Settings::destructionString,
                *Settings::destructionStringEnding, *Settings::destruction, getStatsMenu(*Settings::destructionMenu)),
            std::make_shared<StatItem>(StatsValue::illusion, ActorValue::kIllusion, *Settings::illusionString,
                *Settings::illusionStringEnding, *Settings::illusion, getStatsMenu(*Settings::illusionMenu)),
            std::make_shared<StatItem>(StatsValue::restoration, ActorValue::kRestoration, *Settings::restorationString,
                *Settings::restorationStringEnding, *Settings::restoration, getStatsMenu(*Settings::restorationMenu)),
            std::make_shared<StatItem>(StatsValue::oneHandedPowerMod, ActorValue::kOneHandedPowerModifier,
                *Settings::oneHandedPowerModString, *Settings::oneHandedPowerModStringEnding,
                *Settings::oneHandedPowerMod, getStatsMenu(*Settings::oneHandedPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::twoHandedPowerMod, ActorValue::kTwoHandedPowerModifier,
                *Settings::twoHandedPowerModString, *Settings::twoHandedPowerModStringEnding,
                *Settings::twoHandedPowerMod, getStatsMenu(*Settings::twoHandedPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::archeryPowerMod, ActorValue::kMarksmanPowerModifier,
                *Settings::archeryPowerModString, *Settings::archeryPowerModStringEnding, *Settings::archeryPowerMod,
                getStatsMenu(*Settings::archeryPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::blockPowerMod, ActorValue::kBlockPowerModifier,
                *Settings::blockPowerModString, *Settings::blockPowerModStringEnding, *Settings::blockPowerMod,
                getStatsMenu(*Settings::blockPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::smithingPowerMod, ActorValue::kSmithingPowerModifier,
                *Settings::smithingPowerModString, *Settings::smithingPowerModStringEnding, *Settings::smithingPowerMod,
                getStatsMenu(*Settings::smithingPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::heavyArmorPowerMod, ActorValue::kHeavyArmorPowerModifier,
                *Settings::heavyArmorPowerModString, *Settings::heavyArmorPowerModStringEnding,
                *Settings::heavyArmorPowerMod, getStatsMenu(*Settings::heavyArmorPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::lightArmorPowerMod, ActorValue::kLightArmorPowerModifier,
                *Settings::lightArmorPowerModString, *Settings::lightArmorPowerModStringEnding,
                *Settings::lightArmorPowerMod, getStatsMenu(*Settings::lightArmorPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::pickpocketPowerMod, ActorValue::kPickpocketPowerModifier,
                *Settings::pickpocketPowerModString, *Settings::pickpocketPowerModStringEnding,
                *Settings::pickpocketPowerMod, getStatsMenu(*Settings::pickpocketPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::lockpickingPowerMod, ActorValue::kLockpickingPowerModifier,
                *Settings::lockpickingPowerModString, *Settings::lockpickingPowerModStringEnding,
                *Settings::lockpickingPowerMod, getStatsMenu(*Settings::lockpickingPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::sneakPowerMod, ActorValue::kSneakingPowerModifier,
                *Settings::sneakPowerModString, *Settings::sneakPowerModStringEnding, *Settings::sneakPowerMod,
                getStatsMenu(*Settings::sneakPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::alchemyPowerMod, ActorValue::kAlchemyPowerModifier,
                *Settings::alchemyPowerModString, *Settings::alchemyPowerModStringEnding, *Settings::alchemyPowerMod,
                getStatsMenu(*Settings::alchemyPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::speechPowerMod, ActorValue::kSpeechcraftPowerModifier,
                *Settings::speechPowerModString, *Settings::speechPowerModStringEnding, *Settings::speechPowerMod,
                getStatsMenu(*Settings::speechPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::enchantingPowerMod, ActorValue::kEnchantingPowerModifier,
                *Settings::enchantingPowerModString, *Settings::enchantingPowerModStringEnding,
                *Settings::enchantingPowerMod, getStatsMenu(*Settings::enchantingPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::alterationPowerMod, ActorValue::kAlterationPowerModifier,
                *Settings::alterationPowerModString, *Settings::alterationPowerModStringEnding,
                *Settings::alterationPowerMod, getStatsMenu(*Settings::alterationPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::conjurationPowerMod, ActorValue::kConjurationPowerModifier,
                *Settings::conjurationPowerModString, *Settings::conjurationPowerModStringEnding,
                *Settings::conjurationPowerMod, getStatsMenu(*Settings::conjurationPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::destructionPowerMod, ActorValue::kDestructionPowerModifier,
                *Settings::destructionPowerModString, *Settings::destructionPowerModStringEnding,
                *Settings::destructionPowerMod, getStatsMenu(*Settings::destructionPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::illusionPowerMod, ActorValue::kIllusionPowerModifier,
                *Settings::illusionPowerModString, *Settings::illusionPowerModStringEnding, *Settings::illusionPowerMod,
                getStatsMenu(*Settings::illusionPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::restorationPowerMod, ActorValue::kRestorationPowerModifier,
                *Settings::restorationPowerModString, *Settings::restorationPowerModStringEnding,
                *Settings::restorationPowerMod, getStatsMenu(*Settings::restorationPowerModMenu)),
            std::make_shared<StatItem>(StatsValue::speedMult, ActorValue::kSpeedMult, *Settings::speedMultString,
                *Settings::speedMultStringEnding, *Settings::speedMult, getStatsMenu(*Settings::speedMultMenu)),
            std::make_shared<StatItem>(StatsValue::inventoryWeight, ActorValue::kInventoryWeight,
                *Settings::inventoryWeightString, *Settings::inventoryWeightStringEnding, *Settings::inventoryWeight,
                getStatsMenu(*Settings::inventoryWeightMenu)),
            std::make_shared<StatItem>(StatsValue::carryWeight, ActorValue::kCarryWeight, *Settings::carryWeightString,
                *Settings::carryWeightStringEnding, *Settings::carryWeight, getStatsMenu(*Settings::carryWeightMenu)),
            std::make_shared<StatItem>(StatsValue::criticalChance, ActorValue::kCriticalChance,
                *Settings::criticalChanceString, *Settings::criticalChanceStringEnding, *Settings::criticalChance,
                getStatsMenu(*Settings::criticalChanceMenu)),
            std::make_shared<StatItem>(StatsValue::meleeDamage, ActorValue::kMeleeDamage, *Settings::meleeDamageString,
                *Settings::meleeDamageStringEnding, *Settings::meleeDamage, getStatsMenu(*Settings::meleeDamageMenu)),
            std::make_shared<StatItem>(StatsValue::unarmedDamage, ActorValue::kUnarmedDamage,
                *Settings::unarmedDamageString, *Settings::unarmedDamageStringEnding, *Settings::unarmedDamage,
                getStatsMenu(*Settings::unarmedDamageMenu)),
            std::make_shared<StatItem>(StatsValue::absorbChance, ActorValue::kAbsorbChance,
                *Settings::absorbChanceString, *Settings::absorbChanceStringEnding, *Settings::absorbChance,
                getStatsMenu(*Settings::absorbChanceMenu)),
            //we will not set the actor value kWeaponSpeedMult and kLeftWeaponSpeedMultiply here, because some genius thought it is nice that the value 0 and 1 means 100%
            // https://en.uesp.net/wiki/Skyrim_Mod:Actor_Value_Indices as documented here
            std::make_shared<StatItem>(StatsValue::weaponSpeedMult, ActorValue::kNone, *Settings::weaponSpeedMultString,
                *Settings::weaponSpeedMultStringEnding, *Settings::weaponSpeedMult,
                getStatsMenu(*Settings::weaponSpeedMultMenu), getMultiplier(*Settings::weaponSpeedMultMult)),
            std::make_shared<StatItem>(StatsValue::leftWeaponSpeedMult, ActorValue::kNone,
                *Settings::leftWeaponSpeedMultString, *Settings::leftWeaponSpeedMultStringEnding,
                *Settings::leftWeaponSpeedMult, getStatsMenu(*Settings::leftWeaponSpeedMultMenu),
                getMultiplier(*Settings::leftWeaponSpeedMultMult)),
            std::make_shared<StatItem>(StatsValue::rightItemCharge, ActorValue::kRightItemCharge,
                *Settings::rightItemChargeString, *Settings::rightItemChargeStringEnding, *Settings::rightItemCharge,
                getStatsMenu(*Settings::rightItemChargeMenu)),
            std::make_shared<StatItem>(StatsValue::leftItemCharge, ActorValue::kLeftItemCharge,
                *Settings::leftItemChargStringe, *Settings::leftItemChargStringeEnding, *Settings::leftItemCharge,
                getStatsMenu(*Settings::leftItemChargeMenu)),
            std::make_shared<StatItem>(StatsValue::armorPerks, ActorValue::kArmorPerks, *Settings::armorPerksString,
                *Settings::armorPerksStringEnding, *Settings::armorPerks, getStatsMenu(*Settings::armorPerksMenu),
                getMultiplier(*Settings::armorPerksMult)),
            std::make_shared<StatItem>(StatsValue::mass, ActorValue::kMass, *Settings::massString,
                *Settings::massStringEnding, *Settings::mass, getStatsMenu(*Settings::massMenu)),
            std::make_shared<StatItem>(StatsValue::bowStaggerBonus, ActorValue::kBowStaggerBonus,
                *Settings::bowStaggerBonusString, *Settings::bowStaggerBonusStringEnding, *Settings::bowStaggerBonus,
                getStatsMenu(*Settings::bowStaggerBonusMenu)),
            std::make_shared<StatItem>(StatsValue::bypassVendorKeywordCheck, ActorValue::kBypassVendorKeywordCheck,
                *Settings::bypassVendorKeywordCheckString, *Settings::bypassVendorKeywordCheckStringEnding,
                *Settings::bypassVendorKeywordCheck, getStatsMenu(*Settings::bypassVendorKeywordCheckMenu)),
            std::make_shared<StatItem>(StatsValue::bypassVendorStolenCheck, ActorValue::kBypassVendorStolenCheck,
                *Settings::bypassVendorStolenCheckString, *Settings::bypassVendorStolenCheckStringEnding,
                *Settings::bypassVendorStolenCheck, getStatsMenu(*Settings::bypassVendorStolenCheckMenu)),
            std::make_shared<StatItem>(StatsValue::bowSpeedBonus, ActorValue::kBowSpeedBonus,
                *Settings::bowSpeedBonusString, *Settings::bowSpeedBonusStringEnding, *Settings::bowSpeedBonus,
                getStatsMenu(*Settings::bowSpeedBonusMenu)),
            std::make_shared<StatItem>(StatsValue::shoutRecoveryMult, ActorValue::kShoutRecoveryMult,
                *Settings::shoutRecoveryMultString, *Settings::shoutRecoveryMultStringEnding,
                *Settings::shoutRecoveryMult, getStatsMenu(*Settings::shoutRecoveryMultMenu),
                getMultiplier(*Settings::shoutRecoveryMultMult)),
            std::make_shared<StatItem>(StatsValue::movementNoiseMult, ActorValue::kMovementNoiseMult,
                *Settings::movementNoiseMultString, *Settings::movementNoiseMultStringEnding,
                *Settings::movementNoiseMult, getStatsMenu(*Settings::movementNoiseMultMenu),
                getMultiplier(*Settings::movementNoiseMultMult)),
            std::make_shared<StatItem>(StatsValue::dragonSouls, ActorValue::kDragonSouls, *Settings::dragonSoulsString,
                *Settings::dragonSoulsStringEnding, *Settings::dragonSouls, getStatsMenu(*Settings::dragonSoulsMenu)),
            std::make_shared<StatItem>(StatsValue::combatHealthRegenMultiply, ActorValue::kCombatHealthRegenMultiply,
                *Settings::combatHealthRegenMultiplyString, *Settings::combatHealthRegenMultiplyStringEnding,
                *Settings::combatHealthRegenMultiply, getStatsMenu(*Settings::combatHealthRegenMultiplyMenu),
                getMultiplier(*Settings::combatHealthRegenMultiplyMult)),
            std::make_shared<StatItem>(StatsValue::attackDamageMult, ActorValue::kAttackDamageMult,
                *Settings::attackDamageMultString, *Settings::attackDamageMultStringEnding, *Settings::attackDamageMult,
                getStatsMenu(*Settings::attackDamageMultMenu)),
            std::make_shared<StatItem>(StatsValue::beast, ActorValue::kNone, *Settings::beastString,
                *Settings::beastStringEnding, *Settings::beast),
            std::make_shared<StatItem>(StatsValue::xp, ActorValue::kNone, *Settings::xpString,
                *Settings::xpStringEnding, *Settings::xp, StatsMenuValue::mNone),
            std::make_shared<StatItem>(StatsValue::reflectDamage, ActorValue::kReflectDamage,
                *Settings::reflectDamageString, *Settings::reflectDamageStringEnding, *Settings::reflectDamage,
                getStatsMenu(*Settings::reflectDamageMenu)),
            std::make_shared<StatItem>(StatsValue::oneHandedMod, ActorValue::kOneHandedModifier,
                *Settings::oneHandedModString, *Settings::oneHandedModStringEnding, *Settings::oneHandedMod,
                getStatsMenu(*Settings::oneHandedModMenu)),
            std::make_shared<StatItem>(StatsValue::twoHandedMod, ActorValue::kTwoHandedModifier,
                *Settings::twoHandedModString, *Settings::twoHandedModStringEnding, *Settings::twoHandedMod,
                getStatsMenu(*Settings::twoHandedModMenu)),
            std::make_shared<StatItem>(StatsValue::marksmanMod, ActorValue::kMarksmanModifier,
                *Settings::archeryModString, *Settings::archeryModStringEnding, *Settings::archeryMod,
                getStatsMenu(*Settings::archeryModMenu)),
            std::make_shared<StatItem>(StatsValue::blockMod, ActorValue::kBlockModifier, *Settings::blockModString,
                *Settings::blockModStringEnding, *Settings::blockMod, getStatsMenu(*Settings::blockModMenu)),
            std::make_shared<StatItem>(StatsValue::smithingMod, ActorValue::kSmithingModifier,
                *Settings::smithingModString, *Settings::smithingModStringEnding, *Settings::smithingMod,
                getStatsMenu(*Settings::smithingModMenu)),
            std::make_shared<StatItem>(StatsValue::heavyArmorMod, ActorValue::kHeavyArmorModifier,
                *Settings::heavyArmorModString, *Settings::heavyArmorModStringEnding, *Settings::heavyArmorMod,
                getStatsMenu(*Settings::heavyArmorModMenu)),
            std::make_shared<StatItem>(StatsValue::lightArmorMod, ActorValue::kLightArmorModifier,
                *Settings::lightArmorModString, *Settings::lightArmorModStringEnding, *Settings::lightArmorMod,
                getStatsMenu(*Settings::lightArmorModMenu)),
            std::make_shared<StatItem>(StatsValue::pickpocketMod, ActorValue::kPickpocketModifier,
                *Settings::pickpocketModString, *Settings::pickpocketModStringEnding, *Settings::pickpocketMod,
                getStatsMenu(*Settings::pickpocketModMenu)),
            std::make_shared<StatItem>(StatsValue::lockpickingMod, ActorValue::kLockpickingModifier,
                *Settings::lockpickingModString, *Settings::lockpickingModStringEnding, *Settings::lockpickingMod,
                getStatsMenu(*Settings::lockpickingModMenu)),
            std::make_shared<StatItem>(StatsValue::sneakingMod, ActorValue::kSneakingModifier,
                *Settings::sneakModString, *Settings::sneakModStringEnding, *Settings::sneakMod,
                getStatsMenu(*Settings::sneakModMenu)),
            std::make_shared<StatItem>(StatsValue::alchemyMod, ActorValue::kAlchemyModifier,
                *Settings::alchemyModString, *Settings::alchemyModStringEnding, *Settings::alchemyMod,
                getStatsMenu(*Settings::alchemyModMenu)),
            std::make_shared<StatItem>(StatsValue::speechcraftMod, ActorValue::kSpeechcraftModifier,
                *Settings::speechModString, *Settings::speechModStringEnding, *Settings::speechMod,
                getStatsMenu(*Settings::speechModMenu)),
            std::make_shared<StatItem>(StatsValue::enchantingMod, ActorValue::kEnchantingModifier,
                *Settings::enchantingModString, *Settings::enchantingModStringEnding, *Settings::enchantingMod,
                getStatsMenu(*Settings::enchantingModMenu)),
            std::make_shared<StatItem>(StatsValue::alterationMod, ActorValue::kAlterationModifier,
                *Settings::alterationModString, *Settings::alterationModStringEnding, *Settings::alterationMod,
                getStatsMenu(*Settings::alterationModMenu)),
            std::make_shared<StatItem>(StatsValue::conjurationMod, ActorValue::kConjurationModifier,
                *Settings::conjurationModString, *Settings::conjurationModStringEnding, *Settings::conjurationMod,
                getStatsMenu(*Settings::conjurationModMenu)),
            std::make_shared<StatItem>(StatsValue::destructionMod, ActorValue::kDestructionModifier,
                *Settings::destructionModString, *Settings::destructionModStringEnding, *Settings::destructionMod,
                getStatsMenu(*Settings::destructionModMenu)),
            std::make_shared<StatItem>(StatsValue::illusionMod, ActorValue::kIllusionModifier,
                *Settings::illusionModString, *Settings::illusionModStringEnding, *Settings::illusionMod,
                getStatsMenu(*Settings::illusionModMenu)),
            std::make_shared<StatItem>(StatsValue::restorationMod, ActorValue::kRestorationModifier,
                *Settings::restorationModString, *Settings::restorationModStringEnding, *Settings::restorationMod,
                getStatsMenu(*Settings::restorationModMenu)),
            std::make_shared<StatItem>(StatsValue::damageArrow, ActorValue::kNone, *Settings::damageArrowString,
                *Settings::damageArrowStringEnding, *Settings::damageArrow, getStatsMenu(*Settings::damageArrowMenu)),
            std::make_shared<StatItem>(StatsValue::damageLeft, ActorValue::kNone, *Settings::damageLeftString,
                *Settings::damageLeftStringEnding, *Settings::damageLeft, getStatsMenu(*Settings::damageLeftMenu)),
        };

        logger::debug("Vector Size is {}"sv, statList.size());
        return statList;
    }

    void PrintStatsVector(std::vector<std::shared_ptr<StatItem>>& p_vec) {
        logger::trace("Vector Size is {}"sv, p_vec.size());
        for (auto& element : p_vec) {
            logger::trace("name {}, actor {}, value {}, displayname ({}), ending {}, show {}, guiText ({}), menu {}"sv,
                element->getName(), element->getActor(), element->getValue(), element->getDisplayName(),
                element->getEnding(), element->getShow(), element->getGuiText(), element->getMenu());
        }
    }

    StatFiller() = default;
    StatFiller(const StatFiller&) = delete;
    StatFiller(StatFiller&&) = delete;

    ~StatFiller() = default;

    StatFiller& operator=(const StatFiller&) = delete;
    StatFiller& operator=(StatFiller&&) = delete;
};