//
//  ABUUserInfoForSegment+Private.h
//  ABUAdSDK
//
//  Created by heyinyin on 2021/2/26.
//

#import "ABUUserInfoForSegment.h"

@interface ABUUserInfoForSegment (Private)

/// get predefine user info
- (NSDictionary *)getGroupingDimension;

/// get custom user info
- (NSDictionary *)getGroupingDimensionFree;

- (BOOL)isEqualToAnother:(ABUUserInfoForSegment *)another;
@end
