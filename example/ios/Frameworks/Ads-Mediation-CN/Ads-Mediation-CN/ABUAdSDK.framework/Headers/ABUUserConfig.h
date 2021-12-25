//
//  ABUUserConfig.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 日志级别
typedef NS_ENUM (NSInteger, ABUAdSDKLogLevel) {
    ABUAdSDKLogLevelNone = 0,
    ABUAdSDKLogLevelError = 1,
    ABUAdSDKLogLevelDebug = 1
};

typedef NS_ENUM (NSInteger, ABUAdSDKLogLanguage) {
    ABUAdSDKLogLanguageCH,
    ABUAdSDKLogLanguageEN
};

// Theme mode for iOS.
typedef NS_ENUM(NSInteger, ABUAdSDKThemeStatus) {
    ABUAdSDKThemeStatus_None = -1,
    ABUAdSDKThemeStatus_Normal = 0,
    ABUAdSDKThemeStatus_Night  = 1,
};

@interface ABUUserConfig : NSObject

/// 是否开启日志输出
@property (nonatomic, assign) BOOL logEnable;

/// 设置广告主题，扩展暗黑模式
@property (nonatomic, assign) ABUAdSDKThemeStatus themeStatus;

/// 设置扩展设备信息，如不了解该功能，请勿使用。 如@"[{\"device_id\":\"62271333038\"}]"
@property (nonatomic, copy) NSDictionary *extraDeviceMap;

/// 就版本兼容，是否开启调试模式。真实情况由adapter实现，官方adapter中Unity可用
@property (nonatomic, assign) BOOL testMode;

@end

NS_ASSUME_NONNULL_END
