//
// Created by bytedance on 2021/7/8.
// Copyright (c) 2021 wangchao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABUPlayerPlayState.h"

@class ABUNativeAdView;

@protocol ABUNativeAdViewDelegate <NSObject>

@optional

/// 模板广告渲染成功回调，非模板广告不会回调，模板广告可能不会回调
/// @param nativeExpressAdView 模板广告对象
- (void)nativeAdExpressViewRenderSuccess:(ABUNativeAdView *_Nonnull)nativeExpressAdView;

/// 模板广告渲染成功回调，非模板广告不会回调，模板广告可能不会回调
/// @param nativeExpressAdView 模板广告对象
/// @param error 渲染出错原因
- (void)nativeAdExpressViewRenderFail:(ABUNativeAdView *_Nonnull)nativeExpressAdView error:(NSError *_Nullable)error;

/// 广告展示回调，不区分模板与非模板
/// @param nativeAdView 广告对象
- (void)nativeAdDidBecomeVisible:(ABUNativeAdView *_Nonnull)nativeAdView;

/// 广告视频播放状态变更回调，是否回调与adapter实现有关
/// @param nativeAdView 广告对象
/// @param playerState 播放状态
- (void)nativeAdExpressView:(ABUNativeAdView *_Nonnull)nativeAdView stateDidChanged:(ABUPlayerPlayState)playerState;

/// 广告点击事件回调
/// @param nativeAdView 广告对象
/// @param view 广告展示视图
- (void)nativeAdDidClick:(ABUNativeAdView *_Nonnull)nativeAdView withView:(UIView *_Nullable)view;

/// 广告即将展示全屏页面/商店时触发
/// @param nativeAdView 广告视图
- (void)nativeAdViewWillPresentFullScreenModal:(ABUNativeAdView *_Nonnull)nativeAdView;

/// 广告即将退出全屏页面/商店时触发
/// @param nativeAdView 广告视图
- (void)nativeAdViewDidDismissFullScreenModal:(ABUNativeAdView *_Nonnull)nativeAdView;

/// 模板广告点击关闭时触发
/// @param nativeAdView 广告视图
/// @param filterWords 广告关闭原因，adapter开发者透传数据
- (void)nativeAdExpressViewDidClosed:(ABUNativeAdView *_Nullable)nativeAdView closeReason:(NSArray<NSDictionary *> *_Nullable)filterWords;

@end
