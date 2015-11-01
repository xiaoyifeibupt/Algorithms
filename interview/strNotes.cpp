/**
  * 去掉字符串多余的空格
*/
void deExtraBlank(char str[]) {
	char *string_temp = str;
	int i, j;
	for (i = 0, j = 0; string_temp[i] != '\0'; ) {
		//去掉开头的空格
		while (j == 0 && string_temp[i] == ' ')
			++i;
		str[j++] = string_temp[i++];
		if (string_temp[i - 1] == ' ') {
			while (string_temp[i] == ' ')
				++i;
		}		
	}
	//添加结束符
	str[j - 1] = '\0';
}

/**
 * 字符串拷贝
 */
char *strCpy(char *strDst, const char *strSrc) {
    //assert((strDst != NULL) && (strSrc != NULL));
    char *address = strDst;
    while ((*strDst++ = *strSrc++) != '\0') {
        ;
    }
    return address;
}

/**
 * 字符串长度
 */
size_t strLen(const char *str){
    size_t len = 0;
    while ((*str++) != '\0') {
        len++;
    }
    return len;
}

/**
 * 字符串比较
 */
int strCmp(const char *str1, const char *str2) {
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    /* if str1[i] == str2[i], means they all equal to '\0' */
    return (str1[i] == str2[i] ? 0 : (str1[i] > str2[i] ? 1 : -1));
}