package com.tarena.netctoss.utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.tarena.netctoss.utils.DBUtils;

public abstract class BaseDAO<E> {
	// 写一个方法用来封装所有的查询操作
	// 该方法的修饰符可以写成protected,供子类来调用
	// 参数:
	// 1_要执行的SQL语句
	// 2_要设置的参数个数和类型都不确定
	// 返回值:
	protected List<E> query(String querySQL, Object[] params) throws Exception {
		Connection con = null;
		try {
			// 获取连接
			con = DBUtils.getConnection();
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
	 * 封装的所有的更改语句
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

	// 不同的子类用不同的方式把结果集中的数据转换成实体对象
	public abstract E toEntity(ResultSet rs) 
	    throws Exception;

}
