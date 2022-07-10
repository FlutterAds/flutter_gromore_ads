//
//  ABUSdkInitConfig.h
//  ABUAdSDK
//
//  Created by wangchao on 2020/2/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ABUUserConfig;

/// adn初始化配置信息
@interface ABUSdkInitConfig : NSObject

/// 用户自定义配置
@property (nonatomic, strong, readonly) ABUUserConfig *userConfig;

/// appID
@property (nonatomic, copy, readonly) NSString *appID;

/// appKey
@property (nonatomic, copy, readonly) NSString *appKey;

/// adn的标识
@property (nonatomic, copy, readonly) NSString *name;

/// 是否可用状态
@property (nonatomic, assign, readonly) BOOL valid;

/// 是否是自定义adapter，白名单用户权限
@property (nonatomic, assign, readonly) BOOL custom;

/// 自定义adapter初始化的配置类名，该类对象遵循ABUCustomConfigAdapter协议
@property (nonatomic, copy, readonly) NSString *customAdnClassName;

/// 自定义adapter banner广告的配置类名，该类对象遵循ABUCustomBannerAdapter协议
@property (nonatomic, copy, readonly) NSString *customBannerAdapterClassName;

/// 自定义adapter 插屏广告的配置类名，该类对象遵循ABUCustomInterstitialAdapter协议
@property (nonatomic, copy, readonly) NSString *customInterstitialAdapterClassName;

/// 自定义adapter 激励视频广告的配置类名，该类对象遵循ABUCustomRewardedVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customRewardedVideoAdapterClassName;

/// 自定义adapter 全屏广告的配置类名，该类对象遵循ABUCustomFullscreenVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customFullscreenVideoAdapterClassName;

/// 自定义adapter 开屏广告的配置类名，该类对象遵循ABUCustomSplashAdapter协议
@property (nonatomic, copy, readonly) NSString *customSplashAdapterClassName;

/// 自定义adapter native广告的配置类名，该类对象遵循ABUCustomNativeAdapter协议
@property (nonatomic, copy, readonly) NSString *customNativeAdapterClassName;

/// 自定义adapter draw广告的配置类名，该类对象遵循ABUCustomDrawAdapter协议
@property (nonatomic, copy, readonly) NSString *customDrawAdapterClassName;

@end

NS_ASSUME_NONNULL_END
