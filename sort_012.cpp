int count(int s, int e, int q) //q:index_from query 1
{
	sum = presum[e] - presum[s];
	if (array[q] == 1)
		return sum - 1;
	return sum + 1;
}