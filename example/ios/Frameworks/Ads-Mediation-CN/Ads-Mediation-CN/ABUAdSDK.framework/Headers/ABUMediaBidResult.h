//
//  ABUMediaBidResult.h
//  Ads-Mediation-CN
//
//  Created by bytedance on 2021/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABUMediaBidResult : NSObject

@property (nonatomic, assign, readonly) BOOL win;

@property (nonatomic, assign, readonly) NSInteger winnerPrice;

@property (nonatomic, copy, readonly) NSString *lossDescription;

@property (nonatomic, copy, readonly) NSString *winnerAdnID;

@property (nonatomic, copy, readonly) NSDictionary *ext;

@property (nonatomic, strong, readonly) id originNativeAdData;

@end

NS_ASSUME_NONNULL_END
