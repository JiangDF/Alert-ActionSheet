//
//  TKAlertViewController+Private.h
//  
//
//  Created by binluo on 15/5/28.
//  Copyright (c) 2015年 Baijiahulian. All rights reserved.
//

#import "TKAlertViewController.h"

#define kAlertViewBorder         15
#define kAlertViewBounce         20
#define kAlertButtonHeight       44
#define kAlertButtonLineWidth       (1.0/[UIScreen mainScreen].scale)

#define kAlertViewWidth          280
#define kAlertViewMinHeigh       120

#define kAlertViewTitleFont             [UIFont boldSystemFontOfSize:18]
#define kAlertViewTitleTextColor        [UIColor colorWithWhite:50.0/255.0 alpha:1.0]

#define kAlertViewMessageFont           [UIFont systemFontOfSize:16]
#define kAlertViewMessageTextColor      [UIColor colorWithWhite:50.0/255.0 alpha:1.0]

#define kAlertViewLineColor             [UIColor colorWithWhite:179/255.0 alpha:1]

#define kAlertViewButtonFont            [UIFont systemFontOfSize:16]
#define kAlertViewButtonTextColor       [UIColor colorWithRed:0 green:126/255.0 blue:245/255.0 alpha:1]
#define kAlertViewBackgroundColor       [UIColor colorWithWhite:244/255.0 alpha:1]

#define kAnimationCompletionKey         @"AnimationCompletionKey"



@interface TKAlertViewController ()<UIGestureRecognizerDelegate>

@property (nonatomic, assign) BOOL isAnimating;
@property (nonatomic, assign) BOOL cancelWhenDoneAnimating;
@property (nonatomic, assign) TKAlertViewAnimation animationType;
@property (nonatomic, assign) UIOffset offset;
@property (nonatomic, assign) UIOffset  landscapeOffset;

@property (nonatomic, strong) UITapGestureRecognizer *tapGestureRecognizer;
@property (nonatomic, copy)  void (^dismissWhenTapWindowHandler)() ;
@property (nonatomic, readwrite) BOOL dismissBySwipe;

@property (nonatomic, strong) UIPanGestureRecognizer *panGestureRecognizer;

@property (nonatomic, strong) NSMutableArray *actions;

@property (nonatomic, strong) NSMutableDictionary *titleColorDic;
@property (nonatomic, strong) UIColor *windowBackgroundColor;

@property (nonatomic, strong) UIView *wapperView;
@property (nonatomic, strong) UIView *containerView;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UILabel *titleView;
@property (nonatomic, strong) UIView *customView;
@property (nonatomic, strong) UIView *buttonContainerView;

@property (nonatomic, strong) UIDynamicAnimator *animator;
@property (nonatomic, assign) BOOL enabledParallaxEffect;

@end


@interface TKAlertViewController(Private)

- (void)updateFrameForDisplay;

- (void)popupAlertAnimated:(BOOL)animated animationType:(TKAlertViewAnimation)animationType atOffset:(UIOffset)offset;

- (UIButton *)buttonForIndex:(NSInteger)buttonIndex;
- (void)hiddenAlertAnimatedWithCompletion:(void (^)(BOOL finished))completion;
- (void)showAlertWithAnimationType:(TKAlertViewAnimation)animationType completion:(void (^)(BOOL finished))completion1;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated completion:(void (^)(void))completion noteDelegate:(BOOL)noteDelegate;
- (void)dismissAnimated:(BOOL)animated;
- (void)rePopupAnimated:(BOOL)animated;
- (void)removeAlertWindowOrShowAnOldAlert;
- (void)temporarilyHideAnimated:(BOOL)animated;

- (void)showOverlayWindowAniamted;


- (void)addParallaxEffect;
- (void)removeParallaxEffect;

@end