//
//  ABUDrawAdVideoDelegate.h
//  Ads-Mediation-CN
//
//  Created by heyinyin on 2022/4/11.
//
#import <Foundation/Foundation.h>
#import "ABUPlayerPlayState.h"

@class ABUDrawAdView;

@protocol ABUDrawAdVideoDelegate <NSObject>
@optional

/// This method is called when videoadview playback status changed.
/// @param drawAdView draw ad view
/// @param playerState player state after changed
- (void)drawAdVideo:(ABUDrawAdView *_Nullable)drawAdView stateDidChanged:(ABUPlayerPlayState)playerState;


/// This method is called when videoadview's finish view is clicked.
/// @param drawAdView draw ad view
- (void)drawAdVideoDidClick:(ABUDrawAdView *_Nullable)drawAdView;


/// This method is called when videoadview end of play.
/// @param drawAdView draw ad view
- (void)drawAdVideoDidPlayFinish:(ABUDrawAdView *_Nullable)drawAdView;

@end
