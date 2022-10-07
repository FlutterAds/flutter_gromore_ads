//
// Created by bytedance on 2022/4/26.
//

#import <Foundation/Foundation.h>

@interface ABUDislikeReason : NSObject

- (instancetype)initWithID:(NSString *)ID name:(NSString *)name subReasons:(NSArray<ABUDislikeReason *> *)reasons;

@property (nonatomic, copy, readonly) NSString *ID;

@property (nonatomic, copy, readonly) NSString *name;

@property (nonatomic, copy, readonly) NSArray<ABUDislikeReason *> *subReasons;

@property (nonatomic, assign) BOOL isSelected;

@end