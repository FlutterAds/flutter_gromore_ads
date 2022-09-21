//
//  ABUDrawAdsManager.h
//  Ads-Mediation-CN
//
//  Created by heyinyin on 2022/3/31.
//

#import "ABUBaseAd.h"
#import "ABUSize.h"
#import "ABUAdSDKConst.h"
#import "ABUDrawAdView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ABUDrawAdsManagerDelegate;

@interface ABUDrawAdsManager : ABUBaseAd

/// 快速广告构建方法
/// @param unitID 广告位ID
/// @param adSize 广告视图大小
- (instancetype)initWithAdUnitID:(NSString *)unitID adSize:(CGSize)adSize;

/// 广告视图的尺寸，请勿设置为0
@property (nonatomic, assign) CGSize adSize;

/// 广告代理对象
@property (nonatomic, weak) id<ABUDrawAdsManagerDelegate> delegate;

/// 必要，设置广告详情跳转控制器
@property (nonatomic, weak) UIViewController *rootViewController;

/// 加载广告方法
/// @param count 加载广告的数量，建议单次不超过3个
- (void)loadAdDataWithCount:(NSUInteger)count;

@end

@class ABUDrawAdView;
/// Draw 广告回调协议
@protocol ABUDrawAdsManagerDelegate <NSObject>

@optional

/// Draw 广告加载成功回调
/// @param adsManager 广告管理对象
/// @param drawAds 广告视图，GroMore包装视图对象组，包括模板广告和自渲染广告
- (void)drawAdsManagerSuccessToLoad:(ABUDrawAdsManager *_Nonnull)adsManager drawVideoAds:(NSArray<ABUDrawAdView *> *_Nullable)drawAds;

/// Draw 广告加载失败回调
/// @param adsManager 广告管理对象
/// @param error  加载出错信息
- (void)drawAdsManager:(ABUDrawAdsManager *_Nonnull)adsManager didFailWithError:(NSError *_Nullable)error;

/// 暂不开放使用
- (void)drawAdsManager:(ABUDrawAdsManager *_Nonnull)adsManager didWaitingBiddingResultWithParameters:(NSDictionary *)parameters andResumeHandler:(void(^)(NSDictionary *_Nullable data, NSError *_Nullable error))handler;

/// 暂不开放使用
- (void)drawAdsManagerDidFinishLoadAdnAd:(ABUDrawAdsManager *_Nonnull)adsManager drawAd:(ABUDrawAdView *_Nullable)drawAd error:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
