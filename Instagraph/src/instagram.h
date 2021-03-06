#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include <QObject>
#include <QDir>
#include <QVariant>

class Instagram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool busy READ busy NOTIFY busyChanged)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)
    Q_PROPERTY(QString photos_path READ photos_path NOTIFY photos_pathChanged)
public:
    explicit Instagram(QObject *parent = 0);

    bool busy() const;
    QString error() const;
    QString photos_path() const;

public slots:
    void login(bool forse = false);
    void logout();

    void setUsername(QString username){this->m_username = username;}
    void setPassword(QString password){this->m_password = password;}

    QString getUsernameId(){return this->m_username_id;}

    void postImage(QString path, QString caption, QVariantMap location, QString upload_id = "");
    void postVideo(QFile *video);

    void infoMedia(QString mediaId);
    void editMedia(QString mediaId, QString captionText = "");
    void deleteMedia(QString mediaId);
    void removeSelftag(QString mediaId);

    void postComment(QString mediaId, QString commentText);
    void deleteComment(QString mediaId, QString commentId);

    void setPrivateAccount();
    void setPublicAccount();
    void changeProfilePicture(QFile *photo);
    void removeProfilePicture();
    void getProfileData();
    void editProfile(QString url, QString phone, QString first_name, QString biography, QString email, bool gender);
    void getUsernameInfo(QString usernameId);

    void getRecentActivity();
    void getFollowingRecentActivity();

    void getUserTags(QString usernameId);
    void getGeoMedia(QString usernameId);
    void tagFeed(QString tag, QString max_id = "");
    void getTimeLine(QString max_id = "");
    void getUsernameFeed(QString usernameID, QString maxid = "", QString minTimestamp = "");
    void getPopularFeed(QString max_id = "");

    void getMediaLikers(QString mediaId);
    void getMediaComments(QString mediaId);

    void like(QString mediaId);
    void unLike(QString mediaId);

    void follow(QString userId);
    void unFollow(QString userId);
    void block(QString userId);
    void unBlock(QString userId);
    void userFriendship(QString userId);
    void getLikedMedia(QString max_id = "");

    void checkUsername(QString username);
    void createAccount(QString username, QString password, QString email);

    void searchUsername(QString username);

    void searchUsers(QString query);
    void searchTags(QString query);
    void searchFBLocation(QString query);
    void getLocationFeed(QString locationId, QString max_id = "");
    void searchLocation(QString latitude, QString longitude, QString query = "");

    void getv2Inbox();
    void directThread(QString threadId);
    void directMessage(QString recipients, QString text, QString thread_id = "0");
    void directShare(QString mediaId, QString recipients, QString text = "");

    void changePassword(QString oldPassword, QString newPassword);

    void explore(QString max_id = "");

    void getRankedRecipients();
    void getRecentRecipients();

    void getUserFollowings(QString usernameId, QString max_id = "");
    void getUserFollowers(QString usernameId, QString max_id = "");

    void rotateImg(QString filename, qreal deg);
    void squareImg(QString filename);
    void cropImg(QString filename, qreal propos);
    void scaleImg(QString filename);

private:
    QString EXPERIMENTS     = "ig_android_ad_holdout_16m5_universe,ig_android_progressive_jpeg,ig_creation_growth_holdout,ig_android_oppo_app_badging,ig_android_ad_remove_username_from_caption_universe,ig_android_enable_share_to_whatsapp,ig_android_direct_drawing_in_quick_cam_universe,ig_android_ad_always_send_ad_attribution_id_universe,ig_android_universe_video_production,ig_android_direct_plus_button,ig_android_ads_heatmap_overlay_universe,ig_android_http_stack_experiment_2016,ig_android_infinite_scrolling,ig_fbns_blocked,ig_android_post_auto_retry_v7_21,ig_fbns_push,ig_android_video_playback_bandwidth_threshold,ig_android_direct_link_preview,ig_android_direct_typing_indicator,ig_android_preview_capture,ig_android_feed_pill,ig_android_profile_link_iab,ig_android_story_caption,ig_android_network_cancellation,ig_android_histogram_reporter,ig_android_anrwatchdog,ig_android_search_client_matching,ig_android_follow_request_text_buttons,ig_android_feed_zoom,ig_android_drafts_universe,ig_android_disable_comment,ig_android_user_detail_endpoint,ig_android_os_version_blocking,ig_android_blocked_list,ig_android_event_creation,ig_android_high_res_upload_2,ig_android_2fac,ig_android_mark_reel_seen_on_Swipe_forward,ig_android_comment_redesign,ig_android_ad_sponsored_label_universe,ig_android_mentions_dismiss_rule,ig_android_disable_chroma_subsampling,ig_android_share_spinner,ig_android_video_reuse_surface,ig_explore_v3_android_universe,ig_android_media_favorites,ig_android_nux_holdout,ig_android_insta_video_universe,ig_android_search_null_state,ig_android_universe_reel_video_production,liger_instagram_android_univ,ig_android_direct_emoji_picker,ig_feed_holdout_universe,ig_android_direct_send_auto_retry_universe,ig_android_samsung_app_badging,ig_android_disk_usage,ig_android_business_promotion,ig_android_direct_swipe_to_inbox,ig_android_feed_reshare_button_nux,ig_android_react_native_boost_post,ig_android_boomerang_feed_attribution,ig_fbns_shared,ig_fbns_dump_ids,ig_android_react_native_universe,ig_show_promote_button_in_feed,ig_android_ad_metadata_behavior_universe,ig_android_video_loopcount_int,ig_android_inline_gallery_backoff_hours_universe,ig_android_rendering_controls,ig_android_profile_photo_as_media,ig_android_async_stack_image_cache,ig_video_max_duration_qe_preuniverse,ig_video_copyright_whitelist,ig_android_render_stories_with_content_override,ig_android_ad_intent_to_highlight_universe,ig_android_swipe_navigation_x_angle_universe,ig_android_disable_comment_public_test,ig_android_profile,ig_android_direct_blue_tab,ig_android_enable_share_to_messenger,ig_android_fetch_reel_tray_on_resume_universe,ig_android_promote_again,ig_feed_event_landing_page_channel,ig_ranking_following,ig_android_pending_request_search_bar,ig_android_feed_ufi_redesign,ig_android_pending_edits_dialog_universe,ig_android_business_conversion_flow_universe,ig_android_show_your_story_when_empty_universe,ig_android_ad_drop_cookie_early,ig_android_app_start_config,ig_android_fix_ise_two_phase,ig_android_ppage_toggle_universe,ig_android_pbia_normal_weight_universe,ig_android_profanity_filter,ig_ios_su_activity_feed,ig_android_search,ig_android_boomerang_entry,ig_android_mute_story,ig_android_inline_gallery_universe,ig_android_ad_remove_one_tap_indicator_universe,ig_android_view_count_decouple_likes_universe,ig_android_contact_button_redesign_v2,ig_android_periodic_analytics_upload_v2,ig_android_send_direct_typing_indicator,ig_android_ad_holdout_16h2m1_universe,ig_android_react_native_comment_moderation_settings,ig_video_use_sve_universe,ig_android_inline_gallery_no_backoff_on_launch_universe,ig_android_immersive_viewer,ig_android_discover_people_icon,ig_android_profile_follow_back_button,is_android_feed_seen_state,ig_android_dense_feed_unit_cards,ig_android_drafts_video_universe,ig_android_exoplayer,ig_android_add_to_last_post,ig_android_ad_remove_cta_chevron_universe,ig_android_ad_comment_cta_universe,ig_android_search_event_icon,ig_android_channels_home,ig_android_feed,ig_android_dv2_realtime_private_share,ig_android_non_square_first,ig_android_video_interleaved_v2,ig_android_video_cache_policy,ig_android_react_native_universe_kill_switch,ig_android_video_captions_universe,ig_android_follow_search_bar,ig_android_last_edits,ig_android_two_step_capture_flow,ig_android_video_download_logging,ig_android_share_link_to_whatsapp,ig_android_facebook_twitter_profile_photos,ig_android_swipeable_filters_blacklist,ig_android_ad_pbia_profile_tap_universe,ig_android_use_software_layer_for_kc_drawing_universe,ig_android_react_native_ota,ig_android_direct_mutually_exclusive_experiment_universe,ig_android_following_follower_social_context";
    QString LOGIN_EXPERIMENTS   = "ig_android_reg_login_btn_active_state,ig_android_ci_opt_in_at_reg,ig_android_one_click_in_old_flow,ig_android_merge_fb_and_ci_friends_page,ig_android_non_fb_sso,ig_android_mandatory_full_name,ig_android_reg_enable_login_password_btn,ig_android_reg_phone_email_active_state,ig_android_analytics_data_loss,ig_fbns_blocked,ig_android_contact_point_triage,ig_android_reg_next_btn_active_state,ig_android_prefill_phone_number,ig_android_show_fb_social_context_in_nux,ig_android_one_tap_login_upsell,ig_fbns_push,ig_android_phoneid_sync_interval";

    QString m_username;
    QString m_password;
    QString m_debug;
    QString m_username_id;
    QString m_uuid;
    QString m_device_id;
    QString m_token;
    QString m_rank_token;
    QString m_IGDataPath;

    QString m_caption;
    QString m_image_path;

    QDir m_data_path;

    QDir m_photos_path;

    bool m_isLoggedIn = false;

    QString generateDeviceId();

    bool m_busy;
    QString m_error;

    QVariantMap lastUploadLocation;

signals:
    void profileConnected(QVariant answer);
    void profileConnectedFail();

    void autoCompleteUserListReady(QVariant answer);

    void mediaInfoReady(QVariant answer);
    void mediaEdited(QVariant answer);
    void mediaDeleted(QVariant answer);

    void imageConfigureDataReady(QVariant answer);

    void removeSelftagDone(QVariant answer);
    void commentPosted(QVariant answer);
    void commentDeleted(QVariant answer);

    void profilePictureDeleted(QVariant answer);
    void setProfilePrivate(QVariant answer);
    void setProfilePublic(QVariant answer);
    void profileDataReady(QVariant answer);
    void editDataReady(QVariant answer);
    void usernameDataReady(QVariant answer);

    void recentActivityDataReady(QVariant answer);
    void followingRecentDataReady(QVariant answer);

    void userTagsDataReady(QVariant answer);
    void geoMediaDataReady(QVariant answer);
    void tagFeedDataReady(QVariant answer);
    void timeLineDataReady(QVariant answer);
    void userTimeLineDataReady(QVariant answer);
    void popularFeedDataReady(QVariant answer);

    void mediaLikersDataReady(QVariant answer);
    void mediaCommentsDataReady(QVariant answer);
    void likeDataReady(QVariant answer);
    void unLikeDataReady(QVariant answer);

    void followDataReady(QVariant answer);
    void unFollowDataReady(QVariant answer);
    void blockDataReady(QVariant answer);
    void unBlockDataReady(QVariant answer);
    void userFriendshipDataReady(QVariant answer);
    void likedMediaDataReady(QVariant answer);

    void doLogout(QVariant answer);

    void usernameCheckDataReady(QVariant answer);
    void createAccountDataReady(QVariant answer);

    void error(QString message);

    void searchUsernameDataReady(QVariant answer);

    void searchUsersDataReady(QVariant answer);
    void searchTagsDataReady(QVariant answer);
    void searchFBLocationDataReady(QVariant answer);
    void getLocationFeedDataReady(QVariant answer);
    void searchLocationDataReady(QVariant answer);

    void v2InboxDataReady(QVariant answer);
    void directThreadReady(QVariant answer);
    void directMessageReady(QVariant answer);
    void directShareReady(QVariant answer);

    void changePasswordReady(QVariant answer);

    void exploreDataReady(QVariant answer);

    void rankedRecipientsDataReady(QVariant answer);
    void recentRecipientsDataReady(QVariant answer);

    void userFollowingsDataReady(QVariant answer);
    void userFollowersDataReady(QVariant answer);

    void busyChanged();
    void errorChanged();
    void photos_pathChanged();

    void imgSquared();
    void imgRotated();
    void imgCropped();
    void imgScaled();

    void imageUploadProgressDataReady(double answer);

private slots:
    void setUser();
    void doLogin();
    void syncFeatures(bool prelogin = false);
    void autoCompleteUserList();
    void profileConnect(QVariant profile);
    void configurePhoto(QVariant answer);
};

#endif // INSTAGRAM_H
