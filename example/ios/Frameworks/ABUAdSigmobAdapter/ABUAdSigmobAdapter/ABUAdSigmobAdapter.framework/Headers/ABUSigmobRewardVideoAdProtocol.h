//
//  ABUSigmobRewardVideoAdProtocol.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/9/23.
//

#import <Foundation/Foundation.h>
#import "ABUSigmobCommonProtocol.h"


@protocol ABUSigmob_RewardVideoAdDelegate;
@protocol ABUSigmob_RewardVideoAd <NSObject>

@property (nonatomic, weak) id<ABUSigmob_RewardVideoAdDelegate> delegate;
@property (nonatomic, strong, readonly) NSString *placementId;
@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

#pragma mark sigmob 4.1.0 废弃
- (instancetype)initWithPlacementId:(NSString *)placementId request:(WindAdRequest *)request;
#pragma mark sigmob 4.1.0 废弃
- (instancetype)initWithRequest:(WindAdRequest *)request;// v3600
- (void)loadAdData;

/**
*  Called when load the video
*
*  @param bidToken    - the token from bid request within Sigmob Ad Server
*/
- (void)loadAdDataWithBidToken:(NSString *)bidToken;// v3600

/**
 Display video ad.
 @param rootViewController : root view controller for displaying ad.
 @param extras : Extended parameters for displaying ad.
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> *)extras;

@end


@protocol ABUSigmob_RewardVideoAd;
@protocol ABUSigmob_RewardVideoAdDelegate <NSObject>

@required
/**
 This method is called when video ad is can be motivated
 */
- (void)rewardVideoAd:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd reward:(WindRewardInfo *)reward;// v3600

/**
 This method is called when video ad material loaded successfully.
 */
- (void)rewardVideoAdDidLoad:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidLoad:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd didFailWithError:(NSError *)error;

/**
 This method is called when video ad slot will be showing.
 */
- (void)rewardVideoAdWillVisible:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)rewardVideoAdDidVisible:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad is clicked.
 */
- (void)rewardVideoAdDidClick:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)rewardVideoAdDidClickSkip:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;

#pragma mark sigmob 4.1.0 废弃
/**
 This method is called when video ad is about to close.
 */
- (void)rewardVideoAdDidClose:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd reward:(WindRewardInfo *)reward;
#pragma mark sigmob 4.1.0 废弃

/**
 This method is called when video ad is about to close.
 */
- (void)rewardVideoAdDidClose:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd;// v3600

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidPlayFinish:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd didFailWithError:(NSError *)error;

/**
 This method is called when return ads from sigmob ad server.
 */
- (void)rewardVideoAdServerResponse:(id<ABUSigmob_RewardVideoAd>)rewardVideoAd isFillAd:(BOOL)isFillAd;

@end


@protocol ABUSigmob_WindBiddingRewardVideoAdDelegate;
@protocol ABUSigmob_WindBiddingRewardVideoAd<NSObject>

@property (nonatomic, weak) id<ABUSigmob_WindBiddingRewardVideoAdDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *placementId;

@property (nonatomic, getter=isAdReady, readonly) BOOL ready;


- (instancetype)initWithPlacementId:(NSString *)placementId request:(WindAdRequest *)request;

- (void)loadAdData:(NSString *)bidToken;

/**
 Display video ad.
 @param rootViewController : root view controller for displaying ad.
 @param extras : Extended parameters for displaying ad.
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> *)extras;

@end

@protocol ABUSigmob_WindBiddingRewardVideoAd;
@protocol ABUSigmob_WindBiddingRewardVideoAdDelegate<NSObject>

/**
 This method is called when video ad material loaded successfully.
 */
- (void)rewardVideoAdDidLoad:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidLoad:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd didFailWithError:(NSError *)error;

/**
 This method is called when video ad slot will be showing.
 */
- (void)rewardVideoAdWillVisible:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)rewardVideoAdDidVisible:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad is clicked.
 */
- (void)rewardVideoAdDidClick:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)rewardVideoAdDidClickSkip:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd;

/**
 This method is called when video ad is about to close.
 */
- (void)rewardVideoAdDidClose:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd reward:(WindRewardInfo *)reward;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidPlayFinish:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd didFailWithError:(NSError *)error;

/**
 This method is called when return ads from sigmob ad server.
 */
- (void)rewardVideoAdServerResponse:(id<ABUSigmob_WindBiddingRewardVideoAd>)rewardVideoAd isFillAd:(BOOL)isFillAd;

@end


