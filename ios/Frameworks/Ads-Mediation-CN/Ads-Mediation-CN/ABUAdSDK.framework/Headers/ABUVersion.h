//
//  ABUVersion.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/31.
//

#import <Foundation/Foundation.h>

#ifndef ABU_VERSION_H_
#define ABU_VERSION_H_

struct ABUVersion {
    NSInteger great;  // Great version.
    NSInteger major;  // Major version.
    NSInteger minor;  // Minor version.
    NSInteger patch;  // Patch version.
};
typedef struct ABUVersion ABUVersion;

/// create a version struct by values
static inline ABUVersion ABUVersionMake(NSUInteger great, NSUInteger major, NSUInteger minor, NSUInteger patch);

/// create a version struct by string, 4 values required, if less than 4, will be 0 from great, e.g @"1.2.3", great value is 0
static inline ABUVersion ABUVersionFromString(NSString *string);

/// convert version struct to string, may be called for log most
static inline NSString *NSStringFromABUVersion(ABUVersion version);

/// compare two versions, first > second = 1, first < second = -1, first == second = 0
static inline int ABUVersionCompare(ABUVersion version1, ABUVersion version2);

/// compare two versions by string, ABUVersionCompare method will be called
static inline int ABUVersionCompareByString(NSString *version1, NSString *version2);

#pragma mark - Functions

static inline
ABUVersion ABUVersionMake(NSUInteger great, NSUInteger major, NSUInteger minor, NSUInteger patch) {
    ABUVersion version;
    version.great = great;
    version.major = major;
    version.minor = minor;
    version.patch = patch;
    return version;
}

static inline
ABUVersion ABUVersionFromString(NSString *string) {
    NSArray *vcs = [string componentsSeparatedByString:@"."];
    int limitCount = 4;
    ABUVersion version = {0};
    int minCount = MIN(limitCount, (int) vcs.count);
    NSInteger *p = (NSInteger *) &version;
    for (int i = 0; i < minCount; i++) {
        p[i] = [vcs[i] integerValue];
    }
    return version;
}

static inline
NSString *NSStringFromABUVersion(ABUVersion version) {
    NSInteger *p = (NSInteger *) &version;
    NSMutableArray *list = [NSMutableArray arrayWithCapacity:4];
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && list.count == 0) continue;
        [list addObject:@(p[i])];
    }

    return [list componentsJoinedByString:@"."];
}

static inline
int ABUVersionCompare(ABUVersion version1, ABUVersion version2) {
    NSInteger *p1 = (NSInteger *) &version1;
    NSInteger *p2 = (NSInteger *) &version2;
    for (int i = 0; i < 4; i++) {
        if (p1[i] == p2[i]) continue;
        if (p1[i] > p2[i]) return 1;
        return -1;
    }
    return 0;
}

static inline
int ABUVersionCompareByString(NSString *version1, NSString *version2) {
    ABUVersion v1 = ABUVersionFromString(version1);
    ABUVersion v2 = ABUVersionFromString(version2);
    return ABUVersionCompare(v1, v2);
}

#endif
