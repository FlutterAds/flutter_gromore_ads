//
//  ABUSigmobInterstitialAdProtocol.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/9/23.
//

#import <Foundation/Foundation.h>
#import "ABUSigmobCommonProtocol.h"


@protocol ABUSigmob_InterstitialAdDelegate;
@protocol ABUSigmob_InterstitialAd <NSObject>

@property (nonatomic, weak) id<ABUSigmob_InterstitialAdDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *placementId;

@property (nonatomic, getter=isAdReady, readonly) BOOL ready;


- (instancetype)initWithPlacementId:(NSString *)placementId request:(WindAdRequest *)request;

- (instancetype)initWithRequest:(WindAdRequest *)request;// v3600

- (void)loadAdData;


/**
*  Called when load the ad
*
*  @param bidToken    - the token from bid request within Sigmob Ad Server
*/
- (void)loadAdDataWithBidToken:(NSString *)bidToken; // v3600

/**
 Display video ad.
 @param rootViewController : root view controller for displaying ad.
 @param extras : Extended parameters for displaying ad.
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> *)extras;

@end


@protocol ABUSigmob_InterstitialAd;
@protocol ABUSigmob_InterstitialAdDelegate <NSObject>

/**
 This method is called when video ad material loaded successfully.
 */
- (void)intersititialAdDidLoad:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)intersititialAdDidLoad:(id<ABUSigmob_InterstitialAd>)intersititialAd didFailWithError:(NSError *)error;

/**
 This method is called when video ad slot will be showing.
 */
- (void)intersititialAdWillVisible:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)intersititialAdDidVisible:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad is clicked.
 */
- (void)intersititialAdDidClick:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)intersititialAdDidClickSkip:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad is about to close.
 */
- (void)intersititialAdDidClose:(id<ABUSigmob_InterstitialAd>)intersititialAd;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)intersititialAdDidPlayFinish:(id<ABUSigmob_InterstitialAd>)intersititialAd didFailWithError:(NSError *)error;

/**
 This method is called when return ads from sigmob ad server.
 */
- (void)intersititialAdServerResponse:(id<ABUSigmob_InterstitialAd>)intersititialAd isFillAd:(BOOL)isFillAd;

@end
#pragma mark bidding

@protocol ABUSigmob_WindBiddingIntersititialAdDelegate;

@protocol ABUSigmob_WindBiddingIntersititialAd<NSObject>

@property (nonatomic, weak) id<ABUSigmob_WindBiddingIntersititialAdDelegate> delegate;

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

@protocol ABUSigmob_WindBiddingIntersititialAd;
@protocol ABUSigmob_WindBiddingIntersititialAdDelegate<NSObject>
/**
 This method is called when video ad material loaded successfully.
 */
- (void)intersititialAdDidLoad:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)intersititialAdDidLoad:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd didFailWithError:(NSError *)error;

/**
 This method is called when video ad slot will be showing.
 */
- (void)intersititialAdWillVisible:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)intersititialAdDidVisible:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad is clicked.
 */
- (void)intersititialAdDidClick:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)intersititialAdDidClickSkip:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad is about to close.
 */
- (void)intersititialAdDidClose:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)intersititialAdDidPlayFinish:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd didFailWithError:(NSError *)error;

/**
 This method is called when return ads from sigmob ad server.
 */
- (void)intersititialAdServerResponse:(id<ABUSigmob_WindBiddingIntersititialAd>)intersititialAd isFillAd:(BOOL)isFillAd;
@end


