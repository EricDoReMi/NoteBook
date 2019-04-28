package com.tarena.netctoss.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.List;

import com.tarena.netctoss.utils.DBUtils;

public abstract class BaseDAO<E> implements OracleSQL {
	// дһ������������װ���еĲ�ѯ����
	// �÷��������η�����д��protected,������������
	// ����:
	// 1_Ҫִ�е�SQL���
	// 2_Ҫ���õĲ������������Ͷ���ȷ��
	// ����ֵ:
	protected List<E> queryEntity(Connection con,String querySQL, Object[] params)
			throws Exception {
		
		try {
			

			// ����query1ִ�в�ѯ,���ؽ����
			ResultSet rs = query1(con, querySQL, params);

			// ���������������,��װ��ʵ����󷵻�
			List<E> list = new ArrayList<E>();
			while (rs.next()) {
				list.add(toEntity(rs));
			}

			return list;
		} catch (Exception e) {
			e.printStackTrace();
			throw e;
	}
		}

	/**
	 * 
	 * @param querySQL
	 * @param params
	 * @return
	 */
	protected List query(Connection con,String querySQL, Object[] params) throws Exception {
		try {

			// ����query1ִ�в�ѯ,���ؽ����
			ResultSet rs = query1(con, querySQL, params);

			// ���������������,��װ����ͨ���󷵻�

			List list = new ArrayList();

			//���ؽ�����ж��������
			ResultSetMetaData rsmd = rs.getMetaData();
			int count = rsmd.getColumnCount();

			if (count > 1) {
				// ������Ŷ������͵�����
				while (rs.next()) {
					Object[] arr = new Object[count];
					for (int i = 0; i < arr.length; i++) {
						arr[i] = rs.getObject(i + 1);
					}
					list.add(arr);
				}

			} else {
				// ������ŵ�������
				while (rs.next()) {
					// ResultSet getXXX("����") getXXX(�к�)
					list.add(rs.getObject(1));
				}
			}

			return list;
		} catch (Exception e) {
			e.printStackTrace();
			throw e;
	}
		}

	/**
	 * ��ָ��������,ִ�в�ѯ,���ؽ����
	 * 
	 * @param con
	 * @param querySQL
	 * @param params
	 * @return
	 * @throws Exception
	 */
	private ResultSet query1(Connection con, String querySQL, Object[] params)
			throws Exception {
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
		return stmt.executeQuery();
	}

	/**
	 * ��װ�����еĸ������
	 * 
	 * @param updateSQL
	 * @param params
	 * @throws Exception
	 */
	protected void update(Connection con,String updateSQL, Object[] params) throws Exception {
		try {
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
		}

	}

	public Connection begin() throws Exception {
		Connection con = DBUtils.getConnection();
		con.setAutoCommit(false);
		return con;
	}

	public void commit() throws Exception {
		Connection con = DBUtils.getConnection();
		con.commit();
	}

	public void rollback() throws Exception {
		Connection con = DBUtils.getConnection();
		con.rollback();
	}

	public void close() throws Exception {
		DBUtils.closeConnetion();
	}

	// ��ͬ�������ò�ͬ�ķ�ʽ�ѽ�����е�����ת����ʵ�����
	public abstract E toEntity(ResultSet rs) throws Exception;

}
