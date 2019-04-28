package com.tarena.netctoss.utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.tarena.netctoss.utils.DBUtils;

public abstract class BaseDAO<E> {
	// дһ������������װ���еĲ�ѯ����
	// �÷��������η�����д��protected,������������
	// ����:
	// 1_Ҫִ�е�SQL���
	// 2_Ҫ���õĲ������������Ͷ���ȷ��
	// ����ֵ:
	protected List<E> query(String querySQL, Object[] params) throws Exception {
		Connection con = null;
		try {
			// ��ȡ����
			con = DBUtils.getConnection();
			// ���ݲ���querySQL����PreparedStatement
			PreparedStatement stmt = con.prepareStatement(querySQL);
			// ����params�������ò���
			if (params != null) {
				for (int i = 0; i < params.length; i++) {
					// JDBC���жϾ���Ĳ�������
					stmt.setObject(i + 1, params[i]);
					// Oracle������1��ʼ
				}
			}

			ResultSet rs = stmt.executeQuery();
			List<E> list = new ArrayList<E>();
			while (rs.next()) {
				list.add(toEntity(rs));
			}

			return list;
		} catch (Exception e) {
			e.printStackTrace();
			throw e;
		} finally {
			if (con != null)
				con.close();
		}
	}

	/**
	 * ��װ�����еĸ������
	 * @param updateSQL
	 * @param params
	 * @throws Exception
	 */
	protected void update(String updateSQL, Object[] params) throws Exception {
		Connection con = null;
		try {
			con = DBUtils.getConnection();
			PreparedStatement stmt = con.prepareStatement(updateSQL);
			if (params != null) {
				for (int i = 0; i < params.length; i++) {
					stmt.setObject(i + 1, params[i]);
				}
			}
			stmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
			throw e;
		} finally {
			if (con != null)
				con.close();
		}

	}

	// ��ͬ�������ò�ͬ�ķ�ʽ�ѽ�����е�����ת����ʵ�����
	public abstract E toEntity(ResultSet rs) 
	    throws Exception;

}
