//
// Created by bytedance on 2021/6/24.
//

#import <Foundation/Foundation.h>

#pragma mark - 通用参数
/// 聚合广告请求ID，NSString
extern NSString *const ABUAdLoadingParamLinkID;

/// 聚合广告位ID，NSString
extern NSString *const ABUAdLoadingParamMediationRitID;

/// 场景ID，NSString
extern NSString *const ABUAdLoadingParamScenarioID;

/// ADN广告位ID，NSString
extern NSString *const ABUAdLoadingParamMediaRitID;

/// ADN广告位名称，平台配置名称，NSString
extern NSString *const ABUAdLoadingParamMediaName;

/// 请求广告的渲染类型，NSNumber/NSInteger，0 无需区分渲染类型; 1 ADN提供渲染; 2 开发者自渲染
extern NSString *const ABUAdLoadingParamExpressAdType;

/// 是否请求模板广告的描述信息，NSDictionary
extern NSString *const ABUAdLoadingParamExpressAdTypeInfos;

/// 媒体专属扩展参数， NSDictionary
extern NSString *const ABUAdLoadingParamMediaExtra;

/// 广告位中混用其他类型代码位时的代码位类型，0-未混用 3-banner类型 4-信息流类型
extern NSString *const ABUAdLoadingParamAdSubType;

#pragma mark - 自定义补充

/// 自定义Adapter扩展参数， NSString，JSON格式
extern NSString *const ABUAdLoadingParamCustomJson;

/// 获取竞价类型，NSNumber/NSInteger，0-普通广告位 1-Client竞价广告位 100-P层数据位
extern NSString *const ABUAdLoadingParamBiddingType;

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

/// 是否需要开屏卡片功能，NSNumber/BOOL
extern NSString *const ABUAdLoadingParamSPSupportCardView;

/// 自定义底部视图，UIView
extern NSString *const ABUAdLoadingParamSPCustomBottomView;

/// 期望广告尺寸，NSValue/CGSize
extern NSString *const ABUAdLoadingParamSPExpectSize;

/// 开屏超时时间，NSNumber/NSInteger
extern NSString *const ABUAdLoadingParamSPTolerateTimeout;

/// 开屏点击区域，NSNumber/NSInteger/ABUSplashButtonType
extern NSString *const ABUAdLoadingParamSPButtonType;

#pragma mark - Native/Draw广告
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

/// 【可选】直播间信息，NSDictionary
extern NSString *const ABUMediaAdLoadingExtLiveRoom;

/// 【可选】商品信息，NSDictionary
extern NSString *const ABUMediaAdLoadingExtProduct;

/// 【可选】卷信息，NSDictionary
extern NSString *const ABUMediaAdLoadingExtCoupon;
