#include "defs.h"

bool ERdrBltFlip16_ck_cl_ad(BLTFLIP_PARAMS)
{
	EINT32 xctr;
	unsigned EINT32 sc;
	unsigned short *pdd = (unsigned short *)dst;
	unsigned short *psd = (unsigned short *)src;
	while (h)
	{
		for (xctr = 0; xctr < w; xctr++)
		{
			sc = *psd;
			if (sc != colorkey)
			{
					EBCODE_MACRO_COLORIZE(sc, sc, 31, 2016, 63488, 0, 6, 11, 5, colorize, unsigned short)
						sc = EBCODE_MACRO_ADDALPHA(*pdd, sc, 31, 2016, 63488, 32, 2048, 65536);
				*pdd = (unsigned short)sc;
			}
			pdd++; psd += xadd;
		}
		pdd += dstpitch / 2 - w; psd += yadd - w * xadd;
		h--;
	}
	return(true);
}

