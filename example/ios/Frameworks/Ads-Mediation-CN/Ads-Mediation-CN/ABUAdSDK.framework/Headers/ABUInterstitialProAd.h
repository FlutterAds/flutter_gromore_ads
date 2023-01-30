//
//  ABUInterstitialProAd.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/10/14.
//

#import "ABUBaseAd.h"
#import "ABURewardedVideoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUInterstitialProAd, ABUAdapterRewardAdInfo, ABUDictionary;
/// 插全屏广告代理协议
@protocol ABUInterstitialProAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidLoad:(ABUInterstitialProAd *_Nonnull)interstitialProAd;

/// 广告已加载视频素材回调；非视频素材会在load之后立即给出，开发者可统一在该回调后作为离线展示广告的条件
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidDownLoadVideo:(ABUInterstitialProAd *_Nonnull)interstitialProAd;


/// 视频素材广告播放完毕；
/// @param interstitialProAd 广告管理对象
/// @param error 正常播放完毕为nil；异常结束时承载错误信息
- (void)interstitialProAdDidPlayFinish:(ABUInterstitialProAd * _Nonnull)interstitialProAd didFailWithError:(NSError *_Nullable)error;

/// 广告加载失败回调
/// @param interstitialProAd 广告管理对象
/// @param error 加载错误信息
- (void)interstitialProAd:(ABUInterstitialProAd *_Nonnull)interstitialProAd didFailWithError:(NSError *_Nullable)error;

/// 模板广告渲染失败时回调，非模板广告不会回调该方法
/// @param interstitialProAd 广告管理对象
/// @param error 错误信息
- (void)interstitialProAdViewRenderFail:(ABUInterstitialProAd *_Nonnull)interstitialProAd error:(NSError *__nullable)error;

/// 广告展示回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidVisible:(ABUInterstitialProAd *_Nonnull)interstitialProAd;

/// 广告展示失败回调
/// @param interstitialProAd 广告管理对象
/// @param error 展示失败的原因
- (void)interstitialProAdDidShowFailed:(ABUInterstitialProAd *_Nonnull)interstitialProAd error:(NSError *_Nonnull)error;

/// 广告点击事件回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidClick:(ABUInterstitialProAd *_Nonnull)interstitialProAd;

/// 广告点击跳过事件回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidSkip:(ABUInterstitialProAd *_Nonnull)interstitialProAd;


/// 广告关闭事件回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdDidClose:(ABUInterstitialProAd *_Nonnull)interstitialProAd;

/// 即将弹出广告详情页回调
/// @param interstitialProAd 广告管理对象
- (void)interstitialProAdWillPresentFullScreenModal:(ABUInterstitialProAd *_Nonnull)interstitialProAd;

/// 请求的服务器验证成功包括C2C和S2S方法回调;支持全屏视频，目前支持的adn:GDT, Load前可按需传入rewardModel信息
/// @param interstitialProAd 广告管理对象
/// @param rewardInfo 奖励发放验证信息
/// @param verify 是否验证通过
- (void)interstitialProAdServerRewardDidSucceed:(ABUInterstitialProAd *_Nonnull)interstitialProAd rewardInfo:(ABUAdapterRewardAdInfo *_Nullable)rewardInfo verify:(BOOL)verify;

@end


/// 插全屏广告管理类
@interface ABUInterstitialProAd : ABUBaseAd

/// 插屏广告构造方法
/// @param adUnitID 广告位ID
/// @param sizeForInterstitial 针对插屏(非全屏)期望的广告尺寸
- (instancetype _Nonnull )initWithAdUnitID:(NSString *_Nonnull)adUnitID sizeForInterstitial:(CGSize)sizeForInterstitial;

/// 广告代理对象
@property (nonatomic, weak) id<ABUInterstitialProAdDelegate> _Nullable delegate;

///  optional 激励模型，用于全屏视频广告服务端激励回调；目前支持的adn:GDT
@property (nonatomic, strong) ABURewardedVideoModel * _Nonnull rewardModel;

/// 是否静音播放视频，是否真实静音由adapter确定，默认为NO，仅在广告加载前设置有效
@property (nonatomic, assign) BOOL mutedIfCan;

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 展示广告
/// @param viewController 跳转控制器，必传
/// @param extraInfos 扩展信息，可选，与adapter及ADN是否实现有关，字段参见ABUADSDKConst.h中全屏视频、激励视频展示扩展部分
- (BOOL)showAdFromRootViewController:(UIViewController *_Nonnull)viewController extraInfos:(NSDictionary *_Nullable)extraInfos;

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用，返回当前最佳广告的ecpm；当为server bidding ad时访问需要白名单权限；nil为无权限
- (ABURitInfo *_Nullable)getCurrentBestEcpmInfo;

/// 填充后可调用，但推荐展示后调用，返回竞价广告的ecpm；当为server bidding ad时访问需要白名单权限；
- (NSArray<ABURitInfo *> *)multiBiddingEcpmInfos;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *_Nullable)cacheRitList;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

@end

NS_ASSUME_NONNULL_END
