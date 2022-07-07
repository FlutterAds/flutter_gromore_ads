//
//  ABUDrawAdViewDelegate.h
//  Ads-Mediation-CN
//
//  Created by heyinyin on 2022/4/11.
//

#import <Foundation/Foundation.h>
#import "ABUPlayerPlayState.h"

@class ABUDrawAdView;

@protocol ABUDrawAdViewDelegate <NSObject>

@optional

/// 模板广告渲染成功回调，非模板广告不会回调，模板广告可能不会回调
/// @param drawAdView 模板广告对象
- (void)drawAdExpressViewRenderSuccess:(ABUDrawAdView *_Nonnull)drawAdView;

/// 模板广告渲染成功回调，非模板广告不会回调，模板广告可能不会回调
/// @param drawAdView 模板广告对象
/// @param error 渲染出错原因
- (void)drawAdExpressViewRenderFail:(ABUDrawAdView *_Nonnull)drawAdView error:(NSError *_Nullable)error;

/// 模板广告点击关闭时触发
/// @param drawAdView 广告视图
/// @param filterWords 广告关闭原因，adapter开发者透传数据
- (void)drawAdExpressViewDidClosed:(ABUDrawAdView *_Nullable)drawAdView closeReason:(NSArray<NSDictionary *> *_Nullable)filterWords;

/// 非模板广告点击关闭时触发
/// @param drawAdView 广告视图
/// @param filterWords 广告关闭原因，adapter开发者透传数据
- (void)drawAdDidClosed:(ABUDrawAdView *_Nullable)drawAdView closeReason:(NSArray<NSDictionary *> *_Nullable)filterWords;

/// 广告展示回调，不区分模板与非模板
/// @param drawAdView 广告对象
- (void)drawAdDidBecomeVisible:(ABUDrawAdView *_Nonnull)drawAdView;

/// 广告视频播放状态变更回调，是否回调与adapter实现有关
/// @param drawAdView 广告对象
/// @param playerState 播放状态
- (void)drawAdView:(ABUDrawAdView *_Nonnull)drawAdView stateDidChanged:(ABUPlayerPlayState)playerState;

/// 广告点击事件回调
/// @param drawAdView 广告对象
/// @param view 广告展示视图
- (void)drawAdDidClick:(ABUDrawAdView *_Nonnull)drawAdView withView:(UIView *_Nullable)view;

/// 广告即将展示全屏页面/商店时触发
/// @param drawAdView 广告视图
- (void)drawAdViewWillPresentFullScreenModal:(ABUDrawAdView *_Nonnull)drawAdView;

/// 广告即将关闭全屏页面/商店时触发
/// @param drawAdView 广告视图
- (void)drawAdViewWillDismissFullScreenModal:(ABUDrawAdView *_Nonnull)drawAdView;

@end
