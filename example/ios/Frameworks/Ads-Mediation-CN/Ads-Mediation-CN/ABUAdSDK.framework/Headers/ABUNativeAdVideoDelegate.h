//
// Created by bytedance on 2021/7/8.
// Copyright (c) 2021 wangchao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABUPlayerPlayState.h"

@class ABUNativeAdView;

@protocol ABUNativeAdVideoDelegate <NSObject>

@optional

/// This method is called when videoadview playback status changed.
/// @param nativeAdView native ad view
/// @param playerState player state after changed
- (void)nativeAdVideo:(ABUNativeAdView *_Nullable)nativeAdView stateDidChanged:(ABUPlayerPlayState)playerState;


/// This method is called when videoadview's finish view is clicked.
/// @param nativeAdView native ad view
- (void)nativeAdVideoDidClick:(ABUNativeAdView *_Nullable)nativeAdView;


/// This method is called when videoadview end of play.
/// @param nativeAdView native ad view
- (void)nativeAdVideoDidPlayFinish:(ABUNativeAdView *_Nullable)nativeAdView;


@end
