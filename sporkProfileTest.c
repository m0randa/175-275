//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "sporkProfileTest.h"

void testSporkProfile(){
    testCreateProfileHasCorrectDefaults();
    testParseLineDiscardsWhenExtraInfo();
    testParseLineWorksWithFormat();
    testIsValidProfileAdLevelThree();
    testIsValidProfileAvgRatingNegative();
    testAddProfileWithMaxSporkProfiles();
    testAddProfileExceedsMaxSporkProfiles();
    testReadSporkProfileInvalidFile();
    
    testfindNearbyBusinessesTwoBusinesses();
    testCalculateDistanceIsCorrect();
    testfindNearbyBusinessesWithMinDistanceEqualToDistMiles();
    testfindGoodBusinessesTwoBusinesses();
    
    testGetBestBusinessAdLevelZero();
    testGetBestBusinessAdLevelOne();
    testGetBestBusinessAdLevelTwo();
    testGetBestBusinessListsFirstBusinessAdLevelTwo();
    testGetBestBusinessNoBestBusiness();
}

/*
 * @requirement pass if all members of profile are set to defaults
 * @return pass: 1, fail: 0
 */
int testCreateProfileHasCorrectDefaults(){
    SporkProfile prof;
    prof = createSporkProfile();
    
    if(prof.locX != -1 || prof.locY != -1 || prof.distMiles != -1 || prof.avgRating != -1 || prof.adLevel != -1 || prof.isNearby != false || prof.isGood != false || strlen(prof.businessName) != 0)
        return 0;
    else
        return 1;
}

/*
 * @requirement pass if default profile is returned when extra info is included
 * BusinessName 1.0 2.0 3.0 1 extra
 * @return pass: 1, fail: 0
 */
int testParseLineDiscardsWhenExtraInfo(){
    char line[] = "BusinessName 1.0 2.0 3.0 1 extra";
    SporkProfile prof;
    
    prof = parseLine(line);
    if(prof.locX != -1 || prof.locY != -1 || prof.distMiles != -1 || prof.avgRating != -1 || prof.adLevel != -1 || prof.isNearby != false || prof.isGood != false || strlen(prof.businessName) != 0)
        return 0;
    else
        return 1;
}

/*
 * @requirement pass if all members of profile correctly when line is formatted as:
 * BusinessName 1.0 2.0 3.0 1
 * @return pass: 1, fail: 0
 */
int testParseLineWorksWithFormat(){
    char line[100];
    SporkProfile prof;
    strcpy(line, "BusinessName 1.0 2.0 3.0 1");
    prof = parseLine(line);
    if(prof.locX != 1.0 || prof.locY != 2.0 || prof.avgRating != 3.0 || prof.adLevel != 1 || strcmp(prof.businessName, "BusinessName") != 0)
        return 0;
    else
        return 1;

}

/*
 * @requirement pass if profile with ad level three returns 0 from isValidProfile
 * @return pass: 1, fail: 0
 */
int testIsValidProfileAdLevelThree(){
    SporkProfile prof;
    prof.adLevel = 3;
    prof.avgRating = 0.0;
    strcpy(prof.businessName, "business");
    
    int result;
    result = isValidProfile(prof);
    
    if(result != 0)
        return 0;
    else
        return 1;

}

/*
 * @requirement pass if profile with negative rating returns 0 from isValidProfile
 * @return pass: 1, fail: 0
 */
int testIsValidProfileAvgRatingNegative(){
    SporkProfile prof;
    prof.adLevel = 2;
    prof.avgRating = -1.0;
    strcpy(prof.businessName, "business");
    
    int result;
    result = isValidProfile(prof);
    
    if(result != 0)
        return 0;
    else
        return 1;
    
}


/*
 * @requirement pass if numProfiles is MAX_SPORK_PROFILES when exactly MAX_SPORK_PROFILES valid profiles are given to addProfile
 * @return pass: 1, fail: 0
 */
int testAddProfileWithMaxSporkProfiles(){
    SporkProfile profs[MAX_SPORK_PROFILES];
    int num = MAX_SPORK_PROFILES-1;
    SporkProfile prof;
    prof.locX = 1; prof.locY = 1; prof.distMiles = 1; prof.avgRating = 1; prof.adLevel = 1; prof.isNearby = false; prof.isGood = false; strcpy(prof.businessName, "name");
    addProfile(profs, &num, prof);
    if(num != MAX_SPORK_PROFILES)
        return 0;
    else
        return 1;
}

/*
 * @requirement pass if addProfile returns -1 when MAX_SPORK_PROFILES + 1 valid profiles are passed to addProfile
 * @return pass: 1, fail: 0
 */
int testAddProfileExceedsMaxSporkProfiles(){
    SporkProfile profs[MAX_SPORK_PROFILES];
    int num = MAX_SPORK_PROFILES+1;
    SporkProfile prof;
    prof.locX = 1; prof.locY = 1; prof.distMiles = 1; prof.avgRating = 1; prof.adLevel = 1; prof.isNearby = false; prof.isGood = false; strcpy(prof.businessName, "name");
    int result;
    result = addProfile(profs, &num, prof);
    if(result == -1)
        return 1;
    else
        return 0;
    
}
/*
 * @requirement pass if readSporkDataFromFile returns -1 when file does not exist
 * @return pass: 1, fail: 0
 */
int testReadSporkProfileInvalidFile(){
    SporkProfile profs[MAX_BUSINESSNAME_LEN];
    char name[]= "name";
    int result;
    result = readSporkDataFromFile(profs, name);
    
    if(result != -1)
        return 0;
    else
        return 1;
}

/*
 * @requirement pass if findNearbyBusinesses properly sets two profile's isNearby when one is nearby and the other is not
 * @return pass: 1, fail: 0
 */
int testfindNearbyBusinessesTwoBusinesses(){
    SporkProfile profs[2];
    int num = 2;
    double X = 0.0;
    double Y = 0.0;
    double max = 2.0;
    profs[0].locX = 1.0;
    profs[0].locY = 0.0;
    profs[1].locX = 3.0;
    profs[1].locY = 5.0;
    
    findNearbyBusinesses(profs, num, X, Y, max);
    if(profs[0].isNearby != true || profs[1].isNearby != false)
        return 0;
        
        else
            return 1;

}

/*
 * @requirement pass if findNearbyBusinesses determines a business is near when distance is exactly the same as minDist
 * @return pass: 1, fail: 0
 */
int testfindNearbyBusinessesWithMinDistanceEqualToDistMiles(){
    SporkProfile profs[1];
    int num = 1;
    double X = 0.0;
    double Y = 0.0;
    double max = 2.0;
    profs[0].locX = 2.0;
    profs[0].locY = 0.0;
    
    findNearbyBusinesses(profs, num, X, Y, max);
    if(profs[0].isNearby != true)
        return 0;
    
    else
        return 1;
    
}


/*
 * @requirement pass if calculate distance correctly calculates distance
 * @hint you will need to make the distance is calculated within a margin of error of about .001. You may use the math library.
 * @return pass: 1, fail: 0
 */
int testCalculateDistanceIsCorrect(){
    SporkProfile prof;
    prof.locX = 3.0;
    prof.locY = 0.0;
    double X =0.0;
    double Y = 0.0;
    calculateDistance(&prof, X, Y);
    
    if(fabs(prof.distMiles - 3) <= .001)
        return 1;
    else
    return 0;

}

/*
 * @requirement pass if isNearby correctly returns nearby when distMiles is already calculated for the profile
 * @return pass: 1, fail: 0
 */
int testIsNearbyIsCorrect(){
    double dist = 5.0;
    double max =10.0;
    bool ans;
    ans = isNearBy(dist, max);
    
    if(ans != true)
        return 0;
    else
        return 1;

}


/*
 * @requirement pass if findGoodBusinesses correctly determines isGood for two businesses. One business should be good and another not good
 * @return pass: 1, fail: 0
 */
int testfindGoodBusinessesTwoBusinesses(){
    SporkProfile profs[2];
    int num = 2;
    double minRating = 3.0;
    profs[0].avgRating = 1.0;
    profs[1].avgRating = 5.0;
    findGoodBusinesses(profs, num, minRating);
    
    if(profs[0].isGood != false || profs[1].isGood != true)
        return 0;
    else
        return 1;

}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and both ad levels are zero
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelZero(){
    SporkProfile profs[2];
    int num =2;
    
    profs[0].adLevel = 0;
    profs[0].isGood = true;
    profs[0].isNearby = true;
    
    profs[1].adLevel =0;
    profs[1].isNearby = false;
    profs[1].isGood = false;
    
    int result;
    
    result = getIndexBestBusiness(profs, num);
    if(result != 0)
        return 0;
    else
        return 1;

}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and one ad level is zero and another is 1
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelOne(){
    SporkProfile profs[2];
    int num =2;
    
    profs[0].adLevel = 1;
    profs[0].isGood = true;
    profs[0].isNearby = true;
    
    profs[1].adLevel =0;
    profs[1].isNearby = true;
    profs[1].isGood = true;
    
    int result;
    
    result = getIndexBestBusiness(profs, num);
    if(result != 0)
        return 0;
    else
        return 1;
    
}

/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and one ad level is zero and another is 2
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessAdLevelTwo(){
    SporkProfile profs[2];
    int num =2;
    
    profs[0].adLevel = 2;
    profs[0].isGood = true;
    profs[0].isNearby = true;
    
    profs[1].adLevel =0;
    profs[1].isNearby = true;
    profs[1].isGood = true;
    
    int result;
    
    result = getIndexBestBusiness(profs, num);
    if(result != 0)
        return 0;
    else
        return 1;
    
}
/*
 * @requirement pass if getIndexBestBusiness returns correct index when 2 or more profiles are provided and both ad levels are 2.
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessListsFirstBusinessAdLevelTwo(){
    SporkProfile profs[2];
    int num =2;
    
    profs[0].adLevel = 2;
    profs[0].isGood = true;
    profs[0].isNearby = true;
    
    profs[1].adLevel = 2;
    profs[1].isNearby = true;
    profs[1].isGood = true;
    
    int result;
    
    result = getIndexBestBusiness(profs, num);
    if(result != 0)
        return 0;
    else
        return 1;
    
}

/*
 * @requirement pass if getIndexBestBusiness returns -1 when no business isGood and isNearby
 * @return pass: 1, fail: 0
 */
int testGetBestBusinessNoBestBusiness(){
    SporkProfile profs[2];
    int num =2;
    
    profs[0].adLevel = 1;
    profs[0].isGood = false;
    profs[0].isNearby = false;
    
    profs[1].adLevel = 1;
    profs[1].isNearby = false;
    profs[1].isGood = false;
    
    int result;
    
    result = getIndexBestBusiness(profs, num);
    if(result != -1)
        return 0;
    else
        return 1;
    
}
