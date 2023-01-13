//
//  ABUNewFullscreenVideoAd.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import "ABUBaseAd.h"
#import "ABUAdSDKConst.h"
#import "ABURewardedVideoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUFullscreenVideoAd, ABUAdapterRewardAdInfo, ABUDictionary;

/// 全屏视频广告代理回调
@protocol ABUFullscreenVideoAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidLoad:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告加载失败回调
/// @param fullscreenVideoAd 广告管理对象
/// @param error 错误信息
- (void)fullscreenVideoAd:(ABUFullscreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *_Nullable)error;

/// 广告已加载视频素材回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidDownLoadVideo:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告展示回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidVisible:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告点击详情事件回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidClick:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告点击跳过事件回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidSkip:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告关闭事件回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdDidClose:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 即将弹出详情广告页回调
/// @param fullscreenVideoAd 广告管理对象
- (void)fullscreenVideoAdWillPresentFullScreenModal:(ABUFullscreenVideoAd *)fullscreenVideoAd;

/// 广告视频播放完成或者出错回调
/// @param fullscreenVideoAd 广告管理对象
/// @param error 播放出错时的信息，播放完成时为空
- (void)fullscreenVideoAd:(ABUFullscreenVideoAd *)fullscreenVideoAd didPlayFinishWithError:(NSError *_Nullable)error;

/// 广告展示失败回调
/// @param fullscreenVideoAd 广告管理对象
/// @param error 展示失败的原因
- (void)fullscreenVideoAdDidShowFailed:(ABUFullscreenVideoAd *)fullscreenVideoAd error:(NSError *_Nonnull)error;

/// 请求的服务器验证成功包括C2C和S2S方法回调;支持全屏视频，目前支持的adn:GDT, Load前可按需传入rewardModel信息
/// @param fullscreenVideoAd 广告管理对象
/// @param rewardInfo 奖励发放验证信息
/// @param verify 是否验证通过
- (void)fullscreenVideoAdServerRewardDidSucceed:(ABUFullscreenVideoAd *)fullscreenVideoAd rewardInfo:(ABUAdapterRewardAdInfo *_Nullable)rewardInfo verify:(BOOL)verify;

@end

/// 全屏视频广告管理类
@interface ABUFullscreenVideoAd : ABUBaseAd

/// 广告对象构建方法
/// @param unitID 广告位ID
- (instancetype)initWithAdUnitID:(NSString *)unitID;

/// 广告代理对象
@property (nonatomic, weak) id<ABUFullscreenVideoAdDelegate> delegate;

///  optional 激励模型，用于全屏视频广告服务端激励回调；目前支持的adn:GDT
@property (nonatomic, strong) ABURewardedVideoModel * _Nonnull rewardModel;

/// 是否使用模板广告，只对支持模板广告的第三方SDK有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL getExpressAdIfCan ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上全屏视频客户端将无需区分模板非模板");

/// 是否静音播放视频，是否真实静音由adapter确定，默认为NO，仅在广告加载前设置有效
@property (nonatomic, assign) BOOL mutedIfCan;

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 是否使用GDT express 2.0，对GDT（ ≥ 4.11.60）有效，默认为NO，仅在广告加载前设置有效，优先以平台配置为准
@property (nonatomic, assign) BOOL useExpress2IfCanForGDT ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上配合GdtV4.12.80+全屏视频客户端将无需区分模板2.0");

/// 展示广告
/// @param viewController 跳转控制器，必传
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController;

/// 展示广告
/// @param viewController 跳转控制器，必传
/// @param extroInfos 扩展信息，可选，与adapter及ADN是否实现有关，字段参见ABUADSDKConst.h中全屏视频、激励视频展示扩展部分
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController extroInfos:(NSDictionary *_Nullable)extroInfos;

/// 返回显示广告对应的披露信息，当没有权限访问时Ecpm会返回'-3'
- (ABURitInfo *)getShowEcpmInfo;

/// 填充后可调用，返回当前最佳广告的ecpm；当为server bidding ad时访问需要白名单权限；nil为无权限
- (ABURitInfo *)getCurrentBestEcpmInfo;

/// 填充后可调用，但推荐展示后调用，返回竞价广告的ecpm；当为server bidding ad时访问需要白名单权限；
- (NSArray<ABURitInfo *> *)multiBiddingEcpmInfos;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

/// 广告的扩展信息，可能为nil
- (ABUDictionary *_Nullable)extraData;

/// 填充后可调用，获取广告中的extra信息。目前只支持穿山甲，并且只支持获取coupon, live_room, product信息。
- (nullable NSDictionary *)getMediaExtraInfo;

/// 返回是否为模板广告，值同`getExpressAdIfCan`
@property (nonatomic, assign, readonly) BOOL hasExpressAdGot ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上全屏视频客户端将无需区分模板非模板");

@end

NS_ASSUME_NONNULL_END
