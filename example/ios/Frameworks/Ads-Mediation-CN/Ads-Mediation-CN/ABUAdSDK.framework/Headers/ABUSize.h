//
//  ABUSize.h
//  BUAdSDK
//
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Get the view with the best results by using the predefined size in pixels.
 When it comes to view display, it is recommended to use the same scaling.
*/
typedef NS_ENUM (NSInteger, ABUProposalSize) {
    ABUProposalSize_Banner600_90,
    ABUProposalSize_Banner600_100,
    ABUProposalSize_Banner600_150,
    ABUProposalSize_Banner600_260,
    ABUProposalSize_Banner600_286,
    ABUProposalSize_Banner600_300,
    ABUProposalSize_Banner600_388,
    ABUProposalSize_Banner600_400,
    ABUProposalSize_Banner600_500,
    ABUProposalSize_Feed228_150,
    ABUProposalSize_Feed690_388,
    ABUProposalSize_Interstitial600_400,
    ABUProposalSize_Interstitial600_600,
    ABUProposalSize_Interstitial600_900,
    ABUProposalSize_DrawFullScreen
};

@interface ABUSize : NSObject

// width unit pixel.
@property (nonatomic, assign) NSInteger width;

// height unit pixel.
@property (nonatomic, assign) NSInteger height;

- (NSDictionary *)dictionaryValue;

@end

@interface ABUSize (BU_SizeFactory)
+ (instancetype)sizeBy:(ABUProposalSize)proposalSize;
@end
