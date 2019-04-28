package com.tarena.netctoss.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.List;

import com.tarena.netctoss.utils.DBUtils;

public abstract class BaseDAO<E> implements OracleSQL {
	// 写一个方法用来封装所有的查询操作
	// 该方法的修饰符可以写成protected,供子类来调用
	// 参数:
	// 1_要执行的SQL语句
	// 2_要设置的参数个数和类型都不确定
	// 返回值:
	protected List<E> queryEntity(Connection con,String querySQL, Object[] params)
			throws Exception {
		
		try {
			

			// 调用query1执行查询,返回结果集
			ResultSet rs = query1(con, querySQL, params);

			// 遍历结果集的数据,封装成实体对象返回
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

			// 调用query1执行查询,返回结果集
			ResultSet rs = query1(con, querySQL, params);

			// 遍历结果集的数据,封装成普通对象返回

			List list = new ArrayList();

			//返回结果集中对象的列数
			ResultSetMetaData rsmd = rs.getMetaData();
			int count = rsmd.getColumnCount();

			if (count > 1) {
				// 集合里放对象类型的数组
				while (rs.next()) {
					Object[] arr = new Object[count];
					for (int i = 0; i < arr.length; i++) {
						arr[i] = rs.getObject(i + 1);
					}
					list.add(arr);
				}

			} else {
				// 集合里放单个对象
				while (rs.next()) {
					// ResultSet getXXX("列名") getXXX(列号)
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
	 * 用指定的连接,执行查询,返回结果集
	 * 
	 * @param con
	 * @param querySQL
	 * @param params
	 * @return
	 * @throws Exception
	 */
	private ResultSet query1(Connection con, String querySQL, Object[] params)
			throws Exception {
		// 根据参数querySQL创建PreparedStatement
		PreparedStatement stmt = con.prepareStatement(querySQL);
		// 根据params数组设置参数
		if (params != null) {
			for (int i = 0; i < params.length; i++) {
				// JDBC来判断具体的参数类型
				stmt.setObject(i + 1, params[i]);
				// Oracle参数从1开始
			}
		}
		return stmt.executeQuery();
	}

	/**
	 * 封装的所有的更改语句
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

	// 不同的子类用不同的方式把结果集中的数据转换成实体对象
	public abstract E toEntity(ResultSet rs) throws Exception;

}
