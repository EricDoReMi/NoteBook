package com.tarena.netctoss.entity;

import java.math.BigDecimal;
import java.sql.Date;

public class Cost {
	private Integer id;
	private String costName;
	private BigDecimal baseDuration;
	private BigDecimal baseCost;
	private BigDecimal unitCost;
	private String descr;
	private String status;
	private Date createDate;
	private Date pauseDate;
	private Date closeDate;

	public BigDecimal getBaseDuration() {
		return baseDuration;
	}

	public void setBaseDuration(BigDecimal baseDuration) {
		this.baseDuration = baseDuration;
	}

	public BigDecimal getBaseCost() {
		return baseCost;
	}

	public void setBaseCost(BigDecimal baseCost) {
		this.baseCost = baseCost;
	}

	public BigDecimal getUnitCost() {
		return unitCost;
	}

	public void setUnitCost(BigDecimal unitCost) {
		this.unitCost = unitCost;
	}

	public String getDescr() {
		return descr;
	}

	public void setDescr(String descr) {
		this.descr = descr;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public Date getCreateDate() {
		return createDate;
	}

	public void setCreateDate(Date createDate) {
		this.createDate = createDate;
	}

	public Date getPauseDate() {
		return pauseDate;
	}

	public void setPauseDate(Date pauseDate) {
		this.pauseDate = pauseDate;
	}

	public Date getCloseDate() {
		return closeDate;
	}

	public void setCloseDate(Date closeDate) {
		this.closeDate = closeDate;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getCostName() {
		return costName;
	}

	public void setCostName(String costName) {
		this.costName = costName;
	}

}
