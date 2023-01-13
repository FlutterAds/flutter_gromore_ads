//
//  ABUInterstitialAd.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/25.
//

#import "ABUBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUInterstitialAd, ABUDictionary;

/// 插屏广告代理协议
@protocol ABUInterstitialAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdDidLoad:(ABUInterstitialAd *)interstitialAd;

/// 广告加载失败回调
/// @param interstitialAd 广告管理对象
/// @param error 加载错误信息
- (void)interstitialAd:(ABUInterstitialAd *)interstitialAd didFailWithError:(NSError *_Nullable)error;

/// 模板广告渲染失败时回调，非模板广告不会回调该方法
/// @param interstitialAd 广告管理对象
/// @param error 错误信息
- (void)interstitialAdViewRenderFail:(ABUInterstitialAd *)interstitialAd error:(NSError *__nullable)error;

/// 广告展示回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdDidVisible:(ABUInterstitialAd *)interstitialAd;

/// 广告展示失败回调
/// @param interstitialAd 广告管理对象
/// @param error 展示失败的原因
- (void)interstitialAdDidShowFailed:(ABUInterstitialAd *_Nonnull)interstitialAd error:(NSError *_Nonnull)error;

/// 广告点击事件回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdDidClick:(ABUInterstitialAd *)interstitialAd;

/// 广告关闭事件回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdDidClose:(ABUInterstitialAd *)interstitialAd;

/// 即将弹出广告详情页回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdWillPresentFullScreenModal:(ABUInterstitialAd *)interstitialAd;

/// 广告即将关闭广告详情页回调
/// @param interstitialAd 广告管理对象
- (void)interstitialAdWillDismissFullScreenModal:(ABUInterstitialAd *)interstitialAd;

@end

/// 插屏广告管理类
@interface ABUInterstitialAd : ABUBaseAd

/// 插屏广告构造方法
/// @param adUnitID 广告位ID
/// @param expectSize 期望广告尺寸
- (instancetype)initWithAdUnitID:(NSString *_Nonnull)adUnitID size:(CGSize)expectSize;

/// 广告代理对象
@property (nonatomic, weak) id<ABUInterstitialAdDelegate> delegate;

/// 是否静音播放视频，是否真实静音由adapter确定，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL mutedIfCan;

/// 是否使用GDT express 2.0，对GDT（ ≥ 4.11.60）有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL useExpress2IfCanForGDT ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上配合GdtV4.12.80+插屏视频客户端将无需区分模板2.0");

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 展示广告
/// @param rootViewController 跳转控制器，必传
- (BOOL)showAdFromRootViewController:(UIViewController *_Nonnull)rootViewController;

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用，返回当前最佳广告的ecpm；当为server bidding ad时访问需要白名单权限；nil为无权限
- (ABURitInfo *)getCurrentBestEcpmInfo;

/// 填充后可调用，但推荐展示后调用，返回竞价广告的ecpm；当为server bidding ad时访问需要白名单权限；
- (NSArray<ABURitInfo *> *)multiBiddingEcpmInfos;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

@end

NS_ASSUME_NONNULL_END
