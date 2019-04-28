package com.tarena.netctoss.utils;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.lang3.StringUtils;

public class EntityUtils {
	/**
	 * 把结果集中的数据填充到对象中
	 * 
	 * @param rs
	 * @param obj
	 */
	public static void fillEntity(ResultSet rs, Object obj) throws Exception {
		ResultSetMetaData rsmd = rs.getMetaData();
		for (int i = 1; i <= rsmd.getColumnCount(); i++) {
			String columnName = rsmd.getColumnName(i);
			Object columnValue = rs.getObject(columnName);
			String propertyName = toCamel(columnName);
			if (columnValue != null) {
				BeanUtils.setProperty(obj, propertyName, columnValue);
			}
		}
	}

	/**
	 * 把下划线的命名变成驼峰命名方式
	 * 
	 * @param name
	 * @return
	 */
	private static String toCamel(String name) {
		name = name.toLowerCase();
		String[] arr = name.split("_");
		String camelName = arr[0];
		if (arr.length > 1) {
			for (int i = 1; i < arr.length; i++) {
				// StringUtils.capitalize(String str)将首字母大写
				camelName += StringUtils.capitalize(arr[i]);
			}
		}
		return camelName;
	}

}
