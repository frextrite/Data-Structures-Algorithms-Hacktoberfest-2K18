package Algos;

import java.util.Arrays;
import java.util.Scanner;

public class Range_MinQueries {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();

		int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
		int m = 2 * (int) Math.pow(2, x) - 1;

		int[] seg = new int[m];
		int[] lazy = new int[m];
		Arrays.fill(seg, Integer.MAX_VALUE);
		ConstructTree(a, seg, 0, a.length - 1, 0);
		int qlow = in.nextInt();
		int qhigh = in.nextInt();
		System.out.println(MinRangeQuery(seg, qlow, qhigh, 0, a.length - 1, 0));
	}

	public static void ConstructTree(int[] a, int[] seg, int low, int high, int pos) {
		if (low == high) {
			seg[pos] = a[low];
			return;
		}
		int mid = (low + high) / 2;
		ConstructTree(a, seg, low, mid, 2 * pos + 1);
		ConstructTree(a, seg, mid + 1, high, 2 * pos + 2);
		seg[pos] = Math.min(seg[2 * pos + 1], seg[2 * pos + 2]);
	}

	public static int MinRangeQuery(int[] seg, int qlow, int qhigh, int low, int high, int pos) {
		if (low >= qlow && high <= qhigh) {
			return seg[pos];
		}

		if (high < qlow || low > qhigh) {
			return Integer.MAX_VALUE;
		}

		int mid = (low + high) / 2;

		return Math.min(MinRangeQuery(seg, qlow, qhigh, low, mid, 2 * pos + 1),
				MinRangeQuery(seg, qlow, qhigh, mid + 1, high, 2 * pos + 2));
	}

	// Lazy Propagation
	public static void UpdateRangeQuery(int[] lazy, int[] segment, int delta, int low, int high, int startRange,
			int endRange, int pos) {
		// Base Condition
		if (low > high) {
			return;
		}

		if (lazy[pos] != 0) {
			segment[pos] += lazy[pos];
			if (low != high) {
				lazy[2 * pos + 1] += lazy[pos];
				lazy[2 * pos + 2] += lazy[pos];
			}
			lazy[pos] = 0;
		}
		// No overlap condition
		if (startRange > high || endRange < low) {
			return;
		}
		// Total Overlap Condition
		if (startRange >= low && endRange <= high) {
			segment[pos] += delta;
			if (low != high) {
				lazy[2 * pos + 1] += delta;
				lazy[2 * pos + 2] += delta;
			}
			return;
		}

		// Partial Overlap Condition
		int mid = (low + high) / 2;
		UpdateRangeQuery(lazy, segment, delta, low, mid, startRange, endRange, 2 * pos + 1);
		UpdateRangeQuery(lazy, segment, delta, mid + 1, high, startRange, endRange, 2 * pos + 2);
		segment[pos] = Math.min(segment[2 * pos + 1], segment[2 * pos + 2]);
	}

	public static int MinRangeQueryLazy(int[] segment, int[] lazy, int qlow, int qhigh, int low, int high, int pos) {
		if (lazy[pos] != 0) {
			segment[pos] += lazy[pos];
			if (low != high) {
				lazy[2 * pos + 1] += lazy[pos];
				lazy[2 * pos + 2] += lazy[pos];
			}
			lazy[pos] = 0;
		}

		if (low >= qlow && high <= qhigh) {
			return segment[pos];
		}

		if (high < qlow || low > qhigh) {
			return Integer.MAX_VALUE;
		}

		int mid = (low + high) / 2;

		return Math.min(MinRangeQueryLazy(segment, lazy, qlow, qhigh, low, mid, 2 * pos + 1),
				MinRangeQueryLazy(segment, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2));
	}

}