void strcatR(char *src, char *des)
{
	while(*src)
		*src++;

	while(*des)
		*src++ = *des++;

	
	*src = '\0';
}