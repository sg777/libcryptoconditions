#include<stdio.h>
#include "cryptoconditions.h"
#include "internal.h"
#include "preimage.c"
int main()
{
	
	char *buf=NULL;
	size_t n;
	
	CC *cond=calloc(1,sizeof(CC));
        unsigned char *hash = calloc(1, 32);

        cond->preimage="sg777";
        cond->preimageLength=strlen(cond->preimage);
        sha256(cond->preimage, cond->preimageLength, hash);

		CCType cc_preimageType = { 0, "preimage-sha-256", Condition_PR_preimageSha256, 0, 0, &preimageFingerprint, &preimageCost, &preimageSubtypes, &preimageFromJSON, &preimageToJSON, &preimageFromFulfillment, &preimageToFulfillment, &preimageIsFulfilled, &preimageFree };

		cond->type=&cc_preimageType;
		n=cc_conditionBinary(cond,buf);
		return 0;
}
