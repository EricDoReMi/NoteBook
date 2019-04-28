package com.tarena.netctoss.test;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.lang3.StringUtils;

import com.tarena.netctoss.entity.Account;
import com.tarena.netctoss.utils.DBUtils;

public class TestEntity {
	public static void main(String[] args) throws Exception {
		Connection con = DBUtils.getConnection();
		PreparedStatement stmt = con.prepareStatement("select * from account");
		ResultSet rs = stmt.executeQuery();

		// 想办法知道查询的结果里有多少列,列名是什么

		// 返回结果集的元数据, 元数据中包含有查询得到的
		// 列名,列的类型等信息
		ResultSetMetaData rsmd = rs.getMetaData();
		// // getColumnCount()返回一共有多少列
		// System.out.println(rsmd.getColumnCount());
		// // getColumnName(int index)获取第index列的列名
		// System.out.println(rsmd.getColumnName(10));

		while (rs.next()) {
			Account account = new Account();
			for (int i = 1; i <= rsmd.getColumnCount(); i++) {
				// 列名
				String columnName = rsmd.getColumnName(i);
				// 列值
				Object columnValue = rs.getObject(columnName);
				// 属性名
				String propertyName = toCamel(columnName);

				if (columnValue != null) {
					BeanUtils
					  .setProperty(account, propertyName, columnValue);
				}
			}
			System.out.println(account);
		}

		con.close();

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
