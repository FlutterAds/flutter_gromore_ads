//
//  ABURewardVideoAd.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/25.
//

#import "ABUBaseAd.h"
#import "ABURewardedVideoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ABURewardedVideoAd,ABUAdapterRewardAdInfo, ABUDictionary;

/// 激励视频广告代理协议
@protocol ABURewardedVideoAdDelegate <NSObject>
@optional

/// 广告加载成功回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidLoad:(ABURewardedVideoAd *)rewardedVideoAd;

/// 广告加载失败回调
/// @param rewardedVideoAd 广告管理对象
/// @param error 错误信息
- (void)rewardedVideoAd:(ABURewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error;

/// 广告已加载视频素材回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidDownLoadVideo:(ABURewardedVideoAd *)rewardedVideoAd;

/// 广告展示回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidVisible:(ABURewardedVideoAd *)rewardedVideoAd;

/// 广告展示失败回调
/// @param rewardedVideoAd 广告管理对象
/// @param error 展示失败的原因
- (void)rewardedVideoAdDidShowFailed:(ABURewardedVideoAd *_Nonnull)rewardedVideoAd error:(NSError *_Nonnull)error;

/// 广告点击详情事件回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidClick:(ABURewardedVideoAd *)rewardedVideoAd;

/// 广告点击跳过事件回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidSkip:(ABURewardedVideoAd *)rewardedVideoAd;

/// 广告关闭事件回调
/// @param rewardedVideoAd 广告管理对象
- (void)rewardedVideoAdDidClose:(ABURewardedVideoAd *)rewardedVideoAd;

/// 请求的服务器验证成功包括C2C和S2S方法回调
/// @param rewardedVideoAd 广告管理对象
/// @param verify 是否验证通过
- (void)rewardedVideoAdServerRewardDidSucceed:(ABURewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用 rewardedVideoAdServerRewardDidSucceed:rewardInfo:verify:");

/// 请求的服务器验证成功包括C2C和S2S方法回调
/// @param rewardedVideoAd 广告管理对象
/// @param rewardInfo 奖励发放验证信息
/// @param verify 是否验证通过
- (void)rewardedVideoAdServerRewardDidSucceed:(ABURewardedVideoAd *)rewardedVideoAd rewardInfo:(ABUAdapterRewardAdInfo *_Nullable)rewardInfo verify:(BOOL)verify;

/// 广告视频播放完成或者出错回调
/// @param rewardedVideoAd 广告管理对象
/// @param error 播放出错时的信息，播放完成时为空
- (void)rewardedVideoAd:(ABURewardedVideoAd *)rewardedVideoAd didPlayFinishWithError:(NSError *_Nullable)error;

@end

@interface ABURewardedVideoAd : ABUBaseAd

- (instancetype)initWithAdUnitID:(NSString *)unitID;

/// 激励广告的自定义数据
@property (nonatomic, strong) ABURewardedVideoModel *rewardedVideoModel;

@property (nonatomic, weak) id<ABURewardedVideoAdDelegate> delegate;

/// 再看一次的回调代理；在触发"再看一次"后，展示回调后的一些回调会依此触发，通过该标识判断当次回调是否属于再看一次的回调。支持的adn：Pangle/KS；
/// 再看一次可触发的会滴：visiable/click/clickSkip/playFinesh/rewardedVideoAdServerRewardDidSucceed
@property (nonatomic, weak) id<ABURewardedVideoAdDelegate> rewardPlayAgainDelegate;

/**
 2021-02
 optional
 设定是否静音播放视频，YES = 静音，NO = 非静音
 PS:
 ①仅gdt、ks、mtg支持设定mute
 ②仅适用于视频播放器设定生效
 重点：请在loadAdData前设置,否则不生效
 */
@property (nonatomic, assign) BOOL mutedIfCan;

/**
 Required
 Get a express Ad if SDK can.Default is NO.
 必须设置且只对支持模板广告的第三方SDK有效,默认为NO.
 */
@property (nonatomic, assign) BOOL getExpressAdIfCan ABU_DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，在SDK V2900以上激励视频客户端将无需区分模板非模板");

/// 是否已经准备广告展示，理论上在广告加载回调后即为YES，但受一些因素的影响（例如广告失效），可能为NO。建议在广告展示前调用该方法进行是否可以展示
@property (nonatomic, assign, readonly) BOOL isReady;

/// 展示广告
/// @param viewController 跳转控制器，必传
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController;

/// 展示广告
/// @param viewController 跳转控制器，必传
/// @param extraInfos 扩展信息，可选，与adapter及ADN是否实现有关，字段参见ABUADSDKConst.h中全屏视频、激励视频展示扩展部分
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController extraInfos:(NSDictionary *_Nullable)extraInfos;

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

@end

NS_ASSUME_NONNULL_END
