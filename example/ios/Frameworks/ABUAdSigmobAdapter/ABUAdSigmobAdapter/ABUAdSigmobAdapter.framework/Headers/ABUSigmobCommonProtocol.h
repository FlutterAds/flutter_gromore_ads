//
//  ABUSigmobCommonProtocol.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/9/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern __attribute__((weak)) NSString * const kSMSplashExtraAdSize;
NSString *const kSMSplashExtraAdSize = @"";
extern __attribute__((weak)) NSString * const kSMSplashExtraRootViewController;
NSString *const kSMSplashExtraRootViewController = @"";

typedef NS_ENUM(NSUInteger, WindLogLevel){
    WindLogLevelError=8,
    WindLogLevelWarning=6,
    WindLogLevelInformation=4,
    WindLogLevelDebug=2
};

typedef NS_ENUM (NSInteger, WindConsentStatus) {
    WindConsentUnknown = 0,
    WindConsentAccepted,
    WindConsentDenied,
};

typedef NS_ENUM (NSInteger, WindAgeRestrictedStatus) {
    WindAgeRestrictedStatusUnknow = 0,
    WindAgeRestrictedStatusYES,
    WindAgeRestrictedStatusNO,
};

typedef enum : NSUInteger {
    WindAdult = 0,
    WindChildren = 1,
} WindAdultState;

typedef enum : NSUInteger {
    WindPersonalizedAdvertisingOn = 0,
    WindPersonalizedAdvertisingOff = 1,
} WindPersonalizedAdvertisingState;

#define ABUSigmob_Respond(_object, _selector) [_object respondsToSelector:@selector(_selector)]

typedef void(^WindAdDebugCallBack)(NSString *msg, WindLogLevel level);


@protocol ABUSigmob_WindAdOptions <NSObject>

/// Sigmob平台申请的appId
@property (copy, nonatomic, readonly) NSString* appId;
/// Sigmob平台申请的appKey
@property (copy, nonatomic, readonly) NSString* appKey;

- (instancetype)initWithAppId:(NSString *)appId appKey:(NSString *)appKey usedMediation:(BOOL)usedMediation;

- (instancetype)initWithAppId:(NSString *)appId appKey:(NSString *)appKey;// v3600

@end
typedef NSObject<ABUSigmob_WindAdOptions> WindAdOptions;


@protocol ABUSigmob_WindAds <NSObject>

+ (NSString *)sdkVersion;

// 获取平台唯一ID，需要在一次广告请求后调研，否则返回为nil
+ (NSString *)getUid; // v3600

// Initialize Wind Ads SDK
+ (void) startWithOptions:(WindAdOptions *)options;

/// 初始化后，可以获得SdkToken
+ (NSString *)getSdkToken; // v3600

/**
 *   DeBug开关显示
 *
 *  @param enable true 开启debug，false 关闭debug
 */
+ (void)setDebugEnable:(BOOL)enable;

#pragma mark - GDPR SUPPORT
/**************************  GDPR  *********************************/
+ (WindConsentStatus)getUserGDPRConsentStatus;

+ (void)setUserGDPRConsentStatus:(WindConsentStatus)status;

#pragma mark - Age SUPPORT
/**************************  Age *********************************/
+ (WindAgeRestrictedStatus)getAgeRestrictedStatus;

+ (void)setIsAgeRestrictedUser:(WindAgeRestrictedStatus)status;

+ (NSUInteger)getUserAge;

+ (void)setUserAge:(NSUInteger)age;

#pragma mark - Adult SUPPORT
/**************************  设置是否是成年人 *********************************/
/// WindAdult: 成年人， WindChildren: 未成年人 default=WindAdult
+ (void)setAdult:(WindAdultState)state;
+ (WindAdultState)getAdultState;

#pragma mark - PersonalizedAdvertisin SUPPORT
/// WindPersonalizedAdvertisingOn: 开启个性化推荐， WindPersonalizedAdvertisingOff: 关闭个性化推荐, default=WindPersonalizedAdvertisingOn
+ (void)setPersonalizedAdvertising:(WindPersonalizedAdvertisingState)state;
+ (WindPersonalizedAdvertisingState)getPersonalizedAdvertisingState;

@end
typedef NSObject<ABUSigmob_WindAds> WindAds;


@protocol ABUSigmob_WindAdRequest <NSObject>
@property (nonatomic,copy) NSString *placementId;
@property (nonatomic,copy) NSString *userId;// v3600
@end
@protocol ABUSigmob_WindAdRequestClass <NSObject>
- (id<ABUSigmob_WindAdRequest>)request;

@end
typedef NSObject<ABUSigmob_WindAdRequest> WindAdRequest;


@protocol ABUSigmob_WindRewardInfo <NSObject>
// v3600
#pragma mark sigmob 4.1.0 废弃
/**
 *  The ID of the reward as defind on Self Service
 */
@property (nonatomic, copy  ) NSString  *rewardId;

/**
 *  The reward name as defined on Self Service
 */
@property (nonatomic, copy  ) NSString  *rewardName;

/**
 *  Amount of reward type given to the user
 */
@property (nonatomic, assign) NSInteger rewardAmount;
#pragma mark sigmob 4.1.0 废弃

/**
 The isCompeltedView is Tell you if you've finished watching video.
 */
@property (nonatomic,assign) BOOL isCompeltedView;
@end
typedef NSObject<ABUSigmob_WindRewardInfo> WindRewardInfo;

// v3600
@protocol ABUSigmob_WindMediaView <NSObject>

/**
 * 视频广告时长，单位 s
 */
- (CGFloat)totalTime;

/**
 * 视频广告已播放时长，单位 s
 */
- (CGFloat)currentTime;

/**
 播放静音开关
 @param flag 是否静音
 */
- (void)muteEnable:(BOOL)flag;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放
 */
- (void)stop;

@property (nonatomic, copy) void(^ctaCallback)(UIControl *sender, UIEvent *event);

@end
typedef UIView <ABUSigmob_WindMediaView> WindMediaView;


NS_ASSUME_NONNULL_END
