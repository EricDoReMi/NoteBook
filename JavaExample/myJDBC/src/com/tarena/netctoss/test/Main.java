package com.tarena.netctoss.test;

import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {
		List<Bar> list = new ArrayList<Bar>();
		for (int i = 0; i <= 1024*1024; i++) {
			System.out.println(i);
			list.add(new Bar());
		}
	}
}
