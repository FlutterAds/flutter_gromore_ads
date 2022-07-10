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

typedef void(^WindAdDebugCallBack)(NSString *msg, WindLogLevel level);


@protocol ABUSigmob_WindAdOptions <NSObject>

/// Sigmob平台申请的appId
@property (copy, nonatomic, readonly) NSString* appId;
/// Sigmob平台申请的appKey
@property (copy, nonatomic, readonly) NSString* appKey;
/// 声明是否使用的是聚合 default = NO
@property (nonatomic, assign, readonly) BOOL usedMediation;

- (instancetype)initWithAppId:(NSString *)appId appKey:(NSString *)appKey usedMediation:(BOOL)usedMediation;

@end
typedef NSObject<ABUSigmob_WindAdOptions> WindAdOptions;


@protocol ABUSigmob_WindAds <NSObject>

+ (NSString *)sdkVersion;

// Initialize Wind Ads SDK
+ (void) startWithOptions:(WindAdOptions *)options;

/**
 *   DeBug开关显示
 *
 *  @param enable true 开启debug，false 关闭debug
 */
+ (void)setDebugEnable:(BOOL)enable;


/**
 *   自定义debug 内容回调显示
 *
 *  @param callBack debugBlock，若不设置则在Xcode debug中显示，
 */
+ (void)setDebugCallBack:(WindAdDebugCallBack)callBack;

/// 提供新的资源包，需要把sigmob.bundle的文件放入到新的bundle内。
/// @param name bundle名称（前缀）
+ (void)setNewBundleName:(NSString *)name;




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
@end
@protocol ABUSigmob_WindAdRequestClass <NSObject>
- (id<ABUSigmob_WindAdRequest>)request;

@end
typedef NSObject<ABUSigmob_WindAdRequest> WindAdRequest;


@protocol ABUSigmob_WindRewardInfo <NSObject>
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


/**
 The isCompeltedView is Tell you if you've finished watching video.
 */
@property (nonatomic,assign) BOOL isCompeltedView;
@end
typedef NSObject<ABUSigmob_WindRewardInfo> WindRewardInfo;


NS_ASSUME_NONNULL_END
