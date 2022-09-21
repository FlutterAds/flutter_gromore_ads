//
//  ABUADSDK_const_h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/19.
//

#ifndef ABUADSDK_const_h
#define ABUADSDK_const_h

#pragma mark - 全屏视频、激励视频展示扩展

#pragma mark 扩展展示参数字段 ** swift请勿直接使用枚举，应使用rawValue
/// ABUShowExtroInfoKey, type of scene, only used for pangle SDK now.And the value of key see ABURitSceneType ABURitSceneType
static NSString * ABUShowExtroInfoKeySceneType          = @"ABUShowExtroInfoKeySceneType";

/// scene description, the description defined by the developer, which needs to be assigned when ABUShowExtroInfoKeySceneType = 0
static NSString * ABUShowExtroInfoKeySceneDescription   = @"ABUShowExtroInfoKeySceneDescription";

#pragma mark 扩展展示参数补充

typedef NS_ENUM (NSInteger, ABURitSceneType) {
    // custom
    ABURitSceneType_custom                  = 0,
    // “home_open_bonus”, Login/open rewards (login, sign-in, offline rewards doubling, etc.)
    ABURitSceneType_home_open_bonus         = 1,
    // "home_svip_bonus", Special privileges (VIP privileges, daily rewards, etc.)
    ABURitSceneType_home_svip_bonus         = 2,
    // "home_get_props", Watch rewarded video ad to gain skin, props, levels, skills, etc
    ABURitSceneType_home_get_props          = 3,
    // "home_try_props", Watch rewarded video ad to try out skins, props, levels, skills, etc
    ABURitSceneType_home_try_props          = 4,
    // "home_get_bonus", Watch rewarded video ad to get gold COINS, diamonds, etc
    ABURitSceneType_home_get_bonus          = 5,
    // "home_gift_bonus", Sweepstakes, turntables, gift boxes, etc
    ABURitSceneType_home_gift_bonus         = 6,
    // "game_start_bonus", Before the opening to obtain physical strength, opening to strengthen, opening buff, task props
    ABURitSceneType_game_start_bonus        = 7,
    // "geme_reduce_waiting", Reduce wait and cooldown on skill CD, building CD, quest CD, etc
    ABURitSceneType_game_reduce_waiting     = 8,
    // "game_more_opportunities", More chances (resurrect death, extra game time, decrypt tips, etc.)
    ABURitSceneType_game_more_opportunities = 9,
    // "game_finish_rewards", Settlement multiple times/extra bonus (completion of chapter, victory over boss, first place, etc.)
    ABURitSceneType_game_finish_rewards     = 10,
    // "game_gift_bonus", The game dropped treasure box, treasures and so on
    ABURitSceneType_game_gift_bonus         = 11
};

// 开屏点击区域类型
typedef NS_ENUM(NSInteger, ABUSplashButtonType) {
  ABUSplashButtonTypeFullScreen = 1, // The whole area of splash view will respond to click event
  ABUSplashButtonTypeDownloadBar = 2  // The area of download bar in splash view will respond to click event
};

#pragma mark - 兼容处理
#import "ABUDislikeWords.h"

/// 三方Adn枚举
typedef NS_ENUM (NSInteger, ABUAdnType) {
    ABUAdnNoPermission  = -3,  // 无权限访问
    ABUAdnNoData        = -2,  // 暂时无真实数据，未获取到最佳广告，一般在未展示之前提前调用
    ABUAdnNone          = 0,   // 未知adn
    ABUAdnPangle        = 1,   // pangle -> 穿山甲adn
    ABUAdnAdmob         = 2,   // admob -> 谷歌Admob
    ABUAdnGDT           = 3,   // gdt -> 腾讯广点通adn
    ABUAdnMTG           = 4,   // mintegral -> Mintegral adn
    ABUAdnUnity         = 5,   // unity -> unity adn
    ABUAdnBaidu         = 6,   // baidu -> 百度adn
    ABUAdnKs            = 7,   // ks -> 快手Adn
    ABUAdnSigmob        = 8,   // sigmob -> Sigmob adn
    ABUAdnKlevin        = 9,   // klevin -> Klevin游可赢
};

// MSDK目前实际只有1，2，3，5，7，8
typedef NS_ENUM (NSInteger, ABUAdSlotAdType) {
    ABUAdSlotAdTypeUnknown         = 0,
    ABUAdSlotAdTypeBanner          = 1,     // banner ads
    ABUAdSlotAdTypeInterstitial    = 2,     // interstitial ads
    ABUAdSlotAdTypeSplash          = 3,     // splash ads
    ABUAdSlotAdTypeFeed            = 5,     // feed ads
    ABUAdSlotAdTypeRewardVideo     = 7,     // rewarded video ads
    ABUAdSlotAdTypeFullscreenVideo = 8,     // full-screen video ads
    ABUAdSlotAdTypeDraw            = 9      // draw ads
};

typedef NS_ENUM(NSInteger, ABUAdSlotPosition) {
    ABUAdSlotPositionTop = 1,
    ABUAdSlotPositionBottom = 2,
    ABUAdSlotPositionFeed = 3,
    ABUAdSlotPositionMiddle = 4, // for interstitial ad only
    ABUAdSlotPositionFullscreen = 5,
};

typedef NS_ENUM(NSInteger, ABUBiddingType) {
    ABUBiddingTypeUnknown = -1,
    ABUBiddingTypeNormal = 0,
    ABUBiddingTypeClient = 1,
    ABUBiddingTypeServer = 2,
    ABUBiddingTypeMulti = 3,
    ABUBiddingTypePriority = 100
};


#pragma mark - 其他

#if defined(__has_attribute)
#if __has_attribute(deprecated)
#define ABU_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
#define ABU_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define ABU_DEPRECATED_MSG_ATTRIBUTE(s)
#define ABU_DEPRECATED_ATTRIBUTE
#endif
#else
#define ABU_DEPRECATED_MSG_ATTRIBUTE(s)
#define ABU_DEPRECATED_ATTRIBUTE
#endif

#endif /* ABUADSDK_const_h */
