#include <string.h>
#include <algorithm>
#include "../includes/stringmanip.h"
#include "../includes/constants.h"
namespace KP{
/**
	 * Calculate the exact amount of memory needed to allocate a that consists of the old string with all tags replaced by tag_replacements.
	 * Don't forget the terminating null!
	 *
	 * ex. src="a large ship"
	 *     tag="large"
	 *     tag_replacement="really large"
	 *
	 *     then
	 *     len_src = 14
	 *     numbTagsToReplace=1
	 *     len_tag=5
	 *     len_tag_replacement=12
	 *
	 *     the function should return 22
	 *
	 * \param len_src - length of original string
	 * \param numbTagsToReplace - number of tags to replace in the original string
	 * \param len_tag - length of the tag
	 * \param len_tag_replacement - length of the tag replacement
	 * \return
	 */
	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		int memory = len_src;
		int repLength = len_tag_replacement * numbTagsToReplace;
		int tagLength = len_tag * numbTagsToReplace;
		if (repLength != 0){
			memory -= tagLength;
			memory += repLength+1;
		}
		return memory;
	}

	/**
	 * If src,new_src, tag or tag_replacment are null then returns INVALID_NULL_PTR_DETECTED
	 *
	 * Copies src char string to new_src char string, replaces all tag occurrences with tag_replacement.
	 * Please ensure that new_src is allocated and of proper size before calling this function
	 *
	 * ex.
	 * 	src ="a large bucket on a large ship"
		tag="large"
		tag_replacement="really large"
		then when the function returns
		new_src="a really large bucket on a really large ship"
	 *
	 * \param src  initial char string, may be deleted and reallocated by this function
	 * \param new_src char string with enough space to hold src string with all tag occurrences replaced by tag_replacement
	 * \param tag  the tag to search for
	 * \param tag_replacement  replaces all occurrences of tag
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, tag or tag_replacement is NULL
	 * 		   SUCCESS everything went well, src contains the
	 */
	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){
		if(src == NULL || tag == NULL || tag_replacement == NULL){
			return INVALID_NULL_PTR_DETECTED;
		}
		int src_index = 0;
		int new_index = 0;
		int tag_index = 0;
		int found = 0;
		while (src[src_index] != '\0') {
			found = 0;
			if (src[src_index] == tag[0]) {
				tag_index = 0;

				while (tag[tag_index] != '\0') {
					if(tag[tag_index] == src[src_index+tag_index]) {
						found++;
					}
					else{
						tag_index = strlen(tag);
					}

					tag_index++;
				}
			}
			if (found == strlen(tag)) {
				for(int x = 0; x <= strlen(tag_replacement); x++){
					new_src[new_index+x] = tag_replacement[x];
				}
				new_index += strlen(tag_replacement);
				src_index += found; //after replacing new tag, skips srcindex past the word
			}

			new_src[new_index] = src[src_index];
			//after each while iteration, add oldsrc at index into newsrc
			src_index++;
			new_index++;
		}
		return SUCCESS;

	}

	/**
	 * how often does the string in tag occur in src?
	 *
	 * \param src  initial char string
	 * \param tag  the tag to search for
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, or tag is NULL
	 *         otherwise the number of times tag occurs in src
	 */
	int findNumbOccurrences(const char *src,  const char *tag){
		int occurences = 0;
		int tagSize = strlen(tag);
		int srcSize = strlen(src);
		for(int x = 0; x < srcSize; x++ ) {
			if (*(src+x) == '\0'){
				return occurences;
			}
			else if (*(src+x) == tag[0]) {
				if(strncmp(src+x, tag, tagSize) == 0){
					occurences++;
				}

			}
		}
		return occurences;



	}
}
