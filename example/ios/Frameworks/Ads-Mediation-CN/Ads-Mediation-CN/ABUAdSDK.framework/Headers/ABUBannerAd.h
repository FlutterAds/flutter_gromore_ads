//
//  ABUNewBannerAd.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/28.
//

#import "ABUBaseAd.h"
#import "ABUAdSDKConst.h"

NS_ASSUME_NONNULL_BEGIN
    
@class ABUBannerAd;

/// banner广告代理协议
@protocol ABUBannerAdDelegate <NSObject>
@optional

/// banner广告加载成功回调
/// @param bannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidLoad:(ABUBannerAd *)bannerAd bannerView:(UIView *)bannerView;

/**
 This method is called when bannerAdView ad slot failed to load.
 @param error : the reason of error
 */

/// 广告加载失败回调
/// @param bannerAd 广告操作对象
/// @param error 错误信息
- (void)bannerAd:(ABUBannerAd *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;

/// 广告展示回调
/// @param bannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidBecomeVisible:(ABUBannerAd *)bannerAd bannerView:(UIView *)bannerView;

/// 广告展示回调
/// @param bannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidBecomVisible:(ABUBannerAd *)bannerAd bannerView:(UIView *)bannerView ABU_DEPRECATED_MSG_ATTRIBUTE("Use bannerAdDidBecomeVisible:bannerView: instead");

/// 即将弹出广告详情页
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdWillPresentFullScreenModal:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// 详情广告页将要关闭
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdWillDismissFullScreenModal:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
- (void)bannerAdDidClick:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView;

/// 广告关闭回调
/// @param ABUBannerAd 广告操作对象
/// @param bannerView 广告视图
/// @param filterwords 不喜欢广告的原因，由adapter开发者配置，可能为空
- (void)bannerAdDidClosed:(ABUBannerAd *)ABUBannerAd bannerView:(UIView *)bannerView dislikeWithReason:(NSArray<NSDictionary *> *_Nullable)filterwords;

@end

/// banner广告操作类
@interface ABUBannerAd : ABUBaseAd

/// banner广告操作对象构建
/// @param adUnitID 广告位ID
/// @param rootViewController 页面跳转控制器
/// @param adSize 广告尺寸
/// @param autoRefreshTime 自动轮播定时间隔，有效值在30-120之间，如不启动轮播请设置为0
- (instancetype _Nonnull)initWithAdUnitID:(NSString *_Nonnull)adUnitID
                       rootViewController:(UIViewController *_Nonnull)rootViewController
                                   adSize:(CGSize)adSize
                          autoRefreshTime:(NSInteger)autoRefreshTime ABU_DEPRECATED_MSG_ATTRIBUTE("The interface is about to be deprecated, please use' 'initWithAdUnitID:rootViewController:adSize'[轮播功能(autoRefreshTime)端上已不支持控制，需要在GroMore平台“瀑布流属性配置”模块配置]");

/// banner广告操作对象构建
/// @param adUnitID 广告位ID
/// @param rootViewController 页面跳转控制器
/// @param adSize 广告尺寸
- (instancetype _Nonnull)initWithAdUnitID:(NSString *_Nonnull)adUnitID
                       rootViewController:(UIViewController *_Nonnull)rootViewController
                                   adSize:(CGSize)adSize;

/// 广告代理回调对象
@property (nonatomic, weak) id<ABUBannerAdDelegate> delegate;

/// 广告尺寸，构造方法中传递的尺寸值
@property (nonatomic, assign, readonly) CGSize adSize;

/// 实际的自动轮播定时间隔，有效值在30-120之间
@property (nonatomic, assign, readonly) NSInteger autoRefreshTime __attribute__((unavailable("This attribute is invalid, get the value of refreshTime")));

/// 平台设置的Banner轮播时间间隔, 范围[10, 180], 其他值按0处理, 默认为0
@property (nonatomic, assign, readonly) NSInteger refreshTime;

/// 返回显示广告对应的Adn，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (ABUAdnType)getAdNetworkPlaformId;

/// 返回显示广告对应的rit，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (NSString *_Nullable)getAdNetworkRitId;

/// 返回显示广告对应的ecpm，当未在平台配置ecpm会返回-1，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3 单位：分
- (NSString *_Nullable)getPreEcpm;

/// 返回显示广告对应的Adn名称，当广告加载中未显示会返回-2，当没有权限访问该部分会返回-3
- (NSString *)getAdNetworkPlatformName;

/// 填充后可调用, 返回广告缓存池内所有信息；nil为无权限
- (NSArray<ABURitInfo *> *)cacheRitList;

@end

NS_ASSUME_NONNULL_END
