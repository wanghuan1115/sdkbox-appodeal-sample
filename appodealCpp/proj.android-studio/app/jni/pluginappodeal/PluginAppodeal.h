/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_APPODEAL_H_
#define _PLUGIN_APPODEAL_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class AppodealListener {
    public:
        virtual void onBannerDidLoadAd() = 0;
        virtual void onBannerDidFailToLoadAd() = 0;
        virtual void onBannerDidClick() = 0;
        virtual void onBannerPresent() = 0; // just trigger on android

        virtual void onInterstitialDidLoadAd() = 0;
        virtual void onInterstitialDidFailToLoadAd() = 0;
        virtual void onInterstitialWillPresent() = 0;
        virtual void onInterstitialDidDismiss() = 0;
        virtual void onInterstitialDidClick() = 0;

        virtual void onVideoDidLoadAd() = 0;
        virtual void onVideoDidFailToLoadAd() = 0;
        virtual void onVideoDidPresent() = 0;
        virtual void onVideoWillDismiss() = 0;
        virtual void onVideoDidFinish() = 0;
    };

    class PluginAppodeal {
    public:

        typedef enum {
            AppodealAdTypeInterstitial = 1 << 0,
            AppodealAdTypeVideo        = 1 << 1,
            AppodealAdTypeBanner       = 1 << 2,
            AppodealAdTypeNativeAd     = 1 << 3,
            AppodealAdTypeAll          = AppodealAdTypeInterstitial | AppodealAdTypeVideo | AppodealAdTypeBanner | AppodealAdTypeNativeAd
        } AdType;

        typedef enum {
            AppodealShowStyleInterstitial = 1,
            AppodealShowStyleVideo,
            AppodealShowStyleVideoOrInterstitial,
            AppodealShowStyleBannerTop,
            AppodealShowStyleBannerCenter,
            AppodealShowStyleBannerBottom
        } ShowStyle;

        typedef enum {
            AppodealUserGenderOther = 0,
            AppodealUserGenderMale,
            AppodealUserGenderFemale
        } Gender;

        typedef enum {
            AppodealUserOccupationOther = 0,
            AppodealUserOccupationWork,
            AppodealUserOccupationSchool,
            AppodealUserOccupationUniversity
        } Occupation;

        typedef enum {
            AppodealUserRelationshipOther = 0,
            AppodealUserRelationshipSingle,
            AppodealUserRelationshipDating,
            AppodealUserRelationshipEngaged,
            AppodealUserRelationshipMarried,
            AppodealUserRelationshipSearching
        } Relationship;

        typedef enum {
            AppodealUserSmokingAttitudeNegative = 1,
            AppodealUserSmokingAttitudeNeutral,
            AppodealUserSmokingAttitudePositive
        } SmokingAttitude;

        typedef enum {
            AppodealUserAlcoholAttitudeNegative = 1,
            AppodealUserAlcoholAttitudeNeutral,
            AppodealUserAlcoholAttitudePositive
        } AlcoholAttitude;

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(AppodealListener* listener);

        /**
         * Get the listener
         */
        static AppodealListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();


        static void setDebugEnabled(bool debugEnabled);
        static bool showAd(ShowStyle style);
        static void cacheAd(AdType type);
        static void hideBanner();
        static bool isReadyForShowWithStyle(ShowStyle showStyle);

        //user meta data
        static void setUserVkId(const std::string& vkId);
        static void setUserFacebookId(const std::string& facebookId);
        static void setUserEmail(const std::string& email);
        static void setUserBirthday(const std::string& birthday);
        static void setUserAge(int age);
        static void setUserGender(Gender gender);
        static void setUserOccupation(Occupation occupation);
        static void setUserRelationship(Relationship relationship);
        static void setUserSmokingAttitude(SmokingAttitude smokingAttitude);
        static void setUserAlcoholAttitude(AlcoholAttitude alcoholAttitude);
        static void setUserInterests(const std::string& interests);

    };
}

#endif
