static bool comp(struct Item Item1, struct Item Item2) {
	return Item1.value * Item2.weight > Item2.value * Item1.weight;
}
double fractionalKnapsack(int W, Item arr[], int n)
{

	sort(arr, arr + n, comp);
	int curweight = 0;
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {

		if (arr[i].weight + curweight <= W) {
			sum += (arr[i].value);
			curweight += arr[i].weight;

		} else {
			int rem = W - curweight;
			sum +=   rem * ((double)arr[i].value / arr[i].weight);
			break;

		}
	}
	return sum;
}
