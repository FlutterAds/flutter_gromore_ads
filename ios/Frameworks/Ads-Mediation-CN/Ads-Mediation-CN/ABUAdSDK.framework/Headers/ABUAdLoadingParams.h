//
// Created by bytedance on 2021/6/24.
//

#import <Foundation/Foundation.h>

#pragma mark - 通用参数
/// 聚合广告请求ID，NSString
extern NSString *const ABUAdLoadingParamLinkID;

/// 聚合广告位ID，NSString
extern NSString *const ABUAdLoadingParamMediationRitID;

/// ADN广告位ID，NSString
extern NSString *const ABUAdLoadingParamMediaRitID;

/// ADN广告位名称，平台配置名称，NSString
extern NSString *const ABUAdLoadingParamMediaName;

/// 是否请求模板广告，NSNumber/NSInteger，1 express; 2 native; 3 express2.0(for gdt only)
extern NSString *const ABUAdLoadingParamExpressAdType;

/// 是否请求模板广告的描述信息，NSDictionary
extern NSString *const ABUAdLoadingParamExpressAdTypeInfos;

/// 自定义Adapter扩展参数， NSString，JSON格式
extern NSString *const ABUAdLoadingParamCustomJson;

/// 媒体专属扩展参数， NSDictionary
extern NSString *const ABUAdLoadingParamMediaExtra;

#pragma mark - Banner

/// 期望广告尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamBNExpectSize;

#pragma mark - 插屏广告
/// 期望广告尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamISExpectSize;

/// 是否是静音，NSNumber/BOOL
extern NSString *const ABUAdLoadingParamISIsMute;

#pragma mark - 全屏视频

/// 是否是静音，NSNumber/BOOL
extern NSString *const ABUAdLoadingParamFVIsMute;

#pragma mark - 激励视频

/// 是否是静音，NSNumber/BOOL
extern NSString *const ABUAdLoadingParamRVIsMute;

/// 用户标识， NSString
extern NSString *const ABUAdLoadingParamRVUserID;

/// 奖励名称， NSString
extern NSString *const ABUAdLoadingParamRVRewardName;

/// 奖励金额，NSNumber/NSInteger
extern NSString *const ABUAdLoadingParamRVRewardAmount;

/// 扩展信息， NSString
extern NSString *const ABUAdLoadingParamRVExtra;

#pragma mark - Splash广告
/// 期望ZoomOutView， NSNumber/BOOL
extern NSString *const ABUAdLoadingParamSPNeedZoomOutIfCan;

/// 自定义底部视图，UIView
extern NSString *const ABUAdLoadingParamSPCustomBottomView;

/// 期望广告尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamSPExpectSize;

/// 开屏超时时间，NSNumber/NSInteger
extern NSString *const ABUAdLoadingParamSPTolerateTimeout;

/// 开屏点击区域，NSNumber/NSInteger/ABUSplashButtonType
extern NSString *const ABUAdLoadingParamSPButtonType;

#pragma mark - Native广告
/// 期望广告图片尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamNAExpectImageSize;

/// 期望广告尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamNAExpectSize;

/// 是否是静音，NSNumber/BOOL
extern NSString *const ABUAdLoadingParamNAIsMute;

/// 加载广告数量，NSNumber/NSInteger
extern NSString *const ABUAdLoadingParamNALoadAdCount;

#pragma mark - 加载回调参数，即adapter开发者通过`- ***Ad:didLoadSuccess/Fail*** ext:`中NSDictionary回调的数据

/// 【可选】AND广告ECPM，NSString，单位分
extern NSString *const ABUMediaAdLoadingExtECPM;

/// 【可选】AND广告ECPMLevel，NSString
extern NSString *const ABUMediaAdLoadingExtECPMLevel;

/// 【可选】ADN广告的加载标识，NSString
extern NSString *const ABUMediaAdLoadingExtRequestID;

/// 【可选】AND广告唯一标识，NSString
extern NSString *const ABUMediaAdLoadingExtAdID;

/// 【可选】AND广告创意唯一标识，NSString
extern NSString *const ABUMediaAdLoadingExtCreativeID;

