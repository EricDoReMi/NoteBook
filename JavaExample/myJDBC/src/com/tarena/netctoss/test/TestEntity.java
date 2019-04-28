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

		// ��취֪����ѯ�Ľ�����ж�����,������ʲô

		// ���ؽ������Ԫ����, Ԫ�����а����в�ѯ�õ���
		// ����,�е����͵���Ϣ
		ResultSetMetaData rsmd = rs.getMetaData();
		// // getColumnCount()����һ���ж�����
		// System.out.println(rsmd.getColumnCount());
		// // getColumnName(int index)��ȡ��index�е�����
		// System.out.println(rsmd.getColumnName(10));

		while (rs.next()) {
			Account account = new Account();
			for (int i = 1; i <= rsmd.getColumnCount(); i++) {
				// ����
				String columnName = rsmd.getColumnName(i);
				// ��ֵ
				Object columnValue = rs.getObject(columnName);
				// ������
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
	 * ���»��ߵ���������շ�������ʽ
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
				// StringUtils.capitalize(String str)������ĸ��д
				camelName += StringUtils.capitalize(arr[i]);
			}
		}
		return camelName;
	}

}
