//
//  OutlineViewController.h
//  SmtpTestServer
//
//  Created by Oleg Shnitko on 18/11/2009.
//  olegshnitko@gmail.com
//  Copyright © 2009 7touch Group, Inc.
//  All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "SmtpClient.h"

#import "Folder.h"
#import "User.h"

@interface OutlineViewController : NSTreeController
{
@private 
    
    SmtpClient *mSmtpClient;
}

- (IBAction)delete:(id)sender;
- (IBAction)restore:(id)sender;
- (IBAction)copy:(id)sender;

- (IBAction)deliver:(id)sender;

- (IBAction)moveSelectionToTrash:(id) sender;
- (IBAction)deleteSelectionFromTrash:(id) sender;
- (IBAction)restoreSelectionFromTrash:(id) sender;

@property (nonatomic, readonly) BOOL canDelete;
@property (nonatomic, readonly) BOOL canRestore;
@property (nonatomic, readonly) BOOL canCopy;

@property (nonatomic, readonly) BOOL canDeliver;

@property (nonatomic, assign) IBOutlet SmtpClient *smtpClient;

@end


@protocol OutlineViewItem

- (BOOL)isLeaf;
- (NSSet *)outlineViewItems;
- (NSString *)outlineViewTitle;
- (BOOL)isOutlineViewFontBold;
- (NSUInteger)outlineViewFontSize;

- (BOOL)isMoveToTrashMenuHidden;
- (BOOL)isDeleteFromTrashMenuHidden;
- (BOOL)isRestoreFromTrashMenuHidden;

- (NSString *)moveToTrashMenuTitle;
- (NSString *)deleteFromTrashMenuTitle;
- (NSString *)restoreFromTrashMenuTitle;

@end

@interface Folder (OutlineViewItem) <OutlineViewItem>
@end

@interface UserProxy (OutlineViewItem) <OutlineViewItem>
@end
