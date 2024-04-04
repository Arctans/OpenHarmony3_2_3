/*
 * Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "hdmi_reg_dphy.h"
#include "hdmi_product_define.h"

static volatile hdmi2tx_dphy_reg_type *g_hdmi2tx_dphy_regs = NULL;

hi_s32 hdmi_reg_tx_phy_init(hi_char *addr)
{
    g_hdmi2tx_dphy_regs = (hdmi2tx_dphy_reg_type *)(addr);
    return HI_SUCCESS;
}

hi_s32 hdmi_reg_tx_phy_deinit(hi_void)
{
    if (g_hdmi2tx_dphy_regs != HI_NULL) {
        g_hdmi2tx_dphy_regs = HI_NULL;
    }
    return HI_SUCCESS;
}

hi_s32 hdmi_reg_sscin_bypass_en_set(hi_u32 reg_sscin_bypass_en)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_inssc_set hdmitx_inssc;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->ssc_in_set.u32);
    hdmitx_inssc.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_inssc.bits.reg_sscin_bypass_en = reg_sscin_bypass_en;
    hdmi_tx_reg_write(reg_addr, hdmitx_inssc.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_pllfbmash111_en_set(hi_u32 reg_pllfbmash111_en)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_inssc_set hdmitx_inssc;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->ssc_in_set.u32);
    hdmitx_inssc.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_inssc.bits.reg_pllfbmash111_en = reg_pllfbmash111_en;
    hdmi_tx_reg_write(reg_addr, hdmitx_inssc.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_dphy_rst_set(hi_u32 reg_rst)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_dphy_rst hdmitx_dphy;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->dphy_rst.u32);
    hdmitx_dphy.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_dphy.bits.reg_dphy_srst_req = reg_rst;
    hdmi_tx_reg_write(reg_addr, hdmitx_dphy.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_aphy_data_clk_height_set(hi_u32 reg_aphy_data_clk_h)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_afifo_data_sel data_sel;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->afifo_data_sel.u32);
    data_sel.u32 = hdmi_tx_reg_read(reg_addr);
    data_sel.bits.reg_aphy_data_clk_h = reg_aphy_data_clk_h;
    hdmi_tx_reg_write(reg_addr, data_sel.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_aphy_data_clk_low_set(hi_u32 reg_aphy_data_clk_l)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_afifo_clk afifo_clk;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->afifo_data_clk.u32);
    afifo_clk.u32 = hdmi_tx_reg_read(reg_addr);
    afifo_clk.bits.reg_aphy_data_clk_l = reg_aphy_data_clk_l;
    hdmi_tx_reg_write(reg_addr, afifo_clk.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_divsel_set(hi_u32 reg_divsel)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_divsel = reg_divsel;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_gc_txpll_pd_set(hi_u32 reg_gc_txpll_pd)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_txpll_pd = reg_gc_txpll_pd;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_txpll_pd_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    return top_pd.bits.reg_gc_txpll_pd;
}

hi_s32 hdmi_reg_gc_pd_rxsense_set(hi_u32 reg_gc_pd_rxsense)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd_rxsense = reg_gc_pd_rxsense;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_pd_rxsense_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    return top_pd.bits.reg_gc_pd_rxsense;
}

hi_u32 hdmi_reg_gc_pd_rterm_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_reg_read(reg_addr);
    return top_pd.bits.reg_gc_pd_rterm;
}

hi_s32 hdmi_reg_gc_pd_rterm_set(hi_u32 reg_gc_pd_rterm)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd_rterm = reg_gc_pd_rterm;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_gc_pd_ldo_set(hi_u32 reg_gc_pd_ldo)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd_ldo = reg_gc_pd_ldo;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_pd_ldo_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    return top_pd.bits.reg_gc_pd_ldo;
}

hi_s32 hdmi_reg_gc_pd_de_set(hi_u32 reg_gc_pd_de)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd_de = reg_gc_pd_de;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_pd_de_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    return top_pd.bits.reg_gc_pd_de;
}

hi_s32 hdmi_reg_gc_pd_bist_set(hi_u32 reg_gc_pd_bist)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd_bist = reg_gc_pd_bist;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_pd_bist_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);

    return top_pd.bits.reg_gc_pd_bist;
}

hi_s32 hdmi_reg_gc_pd_set(hi_u32 reg_gc_pd)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    top_pd.bits.reg_gc_pd = reg_gc_pd;
    hdmi_tx_reg_write(reg_addr, top_pd.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_gc_pd_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_top_pd top_pd;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_top_misc_ctrl.u32);
    top_pd.u32 = hdmi_tx_reg_read(reg_addr);
    return top_pd.bits.reg_gc_pd;
}

hi_s32 hdmi_reg_isel_main_de_clk_set(hi_u32 reg_isel_main_de_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    driver_imain.bits.reg_isel_main_de_clk = reg_isel_main_de_clk;
    hdmi_tx_reg_write(reg_addr, driver_imain.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_isel_main_de_clk_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    return driver_imain.bits.reg_isel_main_de_clk;
}

hi_s32 hdmi_reg_isel_main_d2_set(hi_u32 reg_isel_main_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    driver_imain.bits.reg_isel_main_d2 = reg_isel_main_d2;
    hdmi_tx_reg_write(reg_addr, driver_imain.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_main_d1_set(hi_u32 reg_isel_main_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    driver_imain.bits.reg_isel_main_d1 = reg_isel_main_d1;
    hdmi_tx_reg_write(reg_addr, driver_imain.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_main_d0_set(hi_u32 reg_isel_main_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    driver_imain.bits.reg_isel_main_d0 = reg_isel_main_d0;
    hdmi_tx_reg_write(reg_addr, driver_imain.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_main_clk_set(hi_u32 reg_isel_main_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);
    driver_imain.bits.reg_isel_main_clk = reg_isel_main_clk;
    hdmi_tx_reg_write(reg_addr, driver_imain.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_d0_set(hi_u32 reg_isel_pre_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_ipre.bits.reg_isel_pre_d0 = reg_isel_pre_d0;
    hdmi_tx_reg_write(reg_addr, driver_ipre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_clk_set(hi_u32 reg_isel_pre_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_ipre.bits.reg_isel_pre_clk = reg_isel_pre_clk;
    hdmi_tx_reg_write(reg_addr, driver_ipre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_main_de_d2_set(hi_u32 reg_isel_main_de_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_ipre.bits.reg_isel_main_de_d2 = reg_isel_main_de_d2;
    hdmi_tx_reg_write(reg_addr, driver_ipre.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_isel_main_de_d2_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);

    return driver_ipre.bits.reg_isel_main_de_d2;
}

hi_s32 hdmi_reg_isel_main_de_d1_set(hi_u32 reg_isel_main_de_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_ipre.bits.reg_isel_main_de_d1 = reg_isel_main_de_d1;
    hdmi_tx_reg_write(reg_addr, driver_ipre.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_isel_main_de_d1_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);

    return driver_ipre.bits.reg_isel_main_de_d1;
}

hi_s32 hdmi_reg_isel_main_de_d0_set(hi_u32 reg_isel_main_de_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_ipre.bits.reg_isel_main_de_d0 = reg_isel_main_de_d0;
    hdmi_tx_reg_write(reg_addr, driver_ipre.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_isel_main_de_d0_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_ipre driver_ipre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_ipre.u32);
    driver_ipre.u32 = hdmi_tx_reg_read(reg_addr);

    return driver_ipre.bits.reg_isel_main_de_d0;
}

hi_u32 hdmi_reg_isel_main_clk_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);

    return driver_imain.bits.reg_isel_main_clk;
}

hi_u32 hdmi_reg_isel_main_d0_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_imain driver_imain;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_imain.u32);
    driver_imain.u32 = hdmi_tx_reg_read(reg_addr);

    return driver_imain.bits.reg_isel_main_d0;
}

hi_s32 hdmi_reg_isel_pre_de_d1_set(hi_u32 reg_isel_pre_de_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_iprede driver_iprede;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_iprede.u32);
    driver_iprede.u32 = hdmi_tx_reg_read(reg_addr);
    driver_iprede.bits.reg_isel_pre_de_d1 = reg_isel_pre_de_d1;
    hdmi_tx_reg_write(reg_addr, driver_iprede.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_de_d0_set(hi_u32 reg_isel_pre_de_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_iprede driver_iprede;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_iprede.u32);
    driver_iprede.u32 = hdmi_tx_reg_read(reg_addr);
    driver_iprede.bits.reg_isel_pre_de_d0 = reg_isel_pre_de_d0;
    hdmi_tx_reg_write(reg_addr, driver_iprede.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_de_clk_set(hi_u32 reg_isel_pre_de_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_iprede driver_iprede;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_iprede.u32);
    driver_iprede.u32 = hdmi_tx_reg_read(reg_addr);
    driver_iprede.bits.reg_isel_pre_de_clk = reg_isel_pre_de_clk;
    hdmi_tx_reg_write(reg_addr, driver_iprede.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_d2_set(hi_u32 reg_isel_pre_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_iprede driver_iprede;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_iprede.u32);
    driver_iprede.u32 = hdmi_tx_reg_read(reg_addr);
    driver_iprede.bits.reg_isel_pre_d2 = reg_isel_pre_d2;
    hdmi_tx_reg_write(reg_addr, driver_iprede.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_isel_pre_d1_set(hi_u32 reg_isel_pre_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_iprede driver_iprede;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_iprede.u32);
    driver_iprede.u32 = hdmi_tx_reg_read(reg_addr);
    driver_iprede.bits.reg_isel_pre_d1 = reg_isel_pre_d1;
    hdmi_tx_reg_write(reg_addr, driver_iprede.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_de_d2_set(hi_u32 reg_rsel_pre_de_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_de_d2 = reg_rsel_pre_de_d2;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_de_d1_set(hi_u32 reg_rsel_pre_de_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_de_d1 = reg_rsel_pre_de_d1;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_de_d0_set(hi_u32 reg_rsel_pre_de_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_de_d0 = reg_rsel_pre_de_d0;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_de_clk_set(hi_u32 reg_rsel_pre_de_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_de_clk = reg_rsel_pre_de_clk;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_d2_set(hi_u32 reg_rsel_pre_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_d2 = reg_rsel_pre_d2;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_d1_set(hi_u32 reg_rsel_pre_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_d1 = reg_rsel_pre_d1;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_d0_set(hi_u32 reg_rsel_pre_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_d0 = reg_rsel_pre_d0;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rsel_pre_clk_set(hi_u32 reg_rsel_pre_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_rsel_pre_clk = reg_rsel_pre_clk;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_rsel_pre_clk_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);

    return (driver_rpre.bits.reg_rsel_pre_clk);
}

hi_u32 hdmi_reg_rsel_pre_d0_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);

    return (driver_rpre.bits.reg_rsel_pre_d0);
}

hi_s32 hdmi_reg_isel_pre_de_d2_set(hi_u32 reg_isel_pre_de_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_driver_rpre driver_rpre;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->aphy_rpre.u32);
    driver_rpre.u32 = hdmi_tx_reg_read(reg_addr);
    driver_rpre.bits.reg_isel_pre_de_d2 = reg_isel_pre_de_d2;
    hdmi_tx_reg_write(reg_addr, driver_rpre.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rt_d2_set(hi_u32 reg_rt_d2)
{
    hi_u32 *reg_addr = NULL;
    aphy_rterm_ctrl rterm_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->rterm_ctrl.u32);
    rterm_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    rterm_ctrl.bits.reg_rt_d2 = reg_rt_d2;
    hdmi_tx_reg_write(reg_addr, rterm_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_test_set(hi_u32 reg_test)
{
    hi_u32 *reg_addr = NULL;
    aphy_test_ctrl test_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->test_ctrl_aphy.u32);
    test_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    test_ctrl.bits.reg_test = reg_test;
    hdmi_tx_reg_write(reg_addr, test_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rt_d1_set(hi_u32 reg_rt_d1)
{
    hi_u32 *reg_addr = NULL;
    aphy_rterm_ctrl rterm_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->rterm_ctrl.u32);
    rterm_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    rterm_ctrl.bits.reg_rt_d1 = reg_rt_d1;
    hdmi_tx_reg_write(reg_addr, rterm_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rt_d0_set(hi_u32 reg_rt_d0)
{
    hi_u32 *reg_addr = NULL;
    aphy_rterm_ctrl rterm_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->rterm_ctrl.u32);
    rterm_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    rterm_ctrl.bits.reg_rt_d0 = reg_rt_d0;
    hdmi_tx_reg_write(reg_addr, rterm_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_rt_clk_set(hi_u32 reg_rt_clk)
{
    hi_u32 *reg_addr = NULL;
    aphy_rterm_ctrl rterm_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->rterm_ctrl.u32);
    rterm_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    rterm_ctrl.bits.reg_rt_clk = reg_rt_clk;
    hdmi_tx_reg_write(reg_addr, rterm_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_gc_txpll_en_sscdiv_set(hi_u32 reg_gc_txpll_en_sscdiv)
{
    hi_u32 *reg_addr = NULL;
    aphy_txpll_ctrl txpll_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->txpll_ctrl.u32);
    txpll_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    txpll_ctrl.bits.reg_gc_txpll_en_sscdiv = reg_gc_txpll_en_sscdiv;
    hdmi_tx_reg_write(reg_addr, txpll_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_txpll_icp_ictrl_set(hi_u32 reg_txpll_icp_ictrl)
{
    hi_u32 *reg_addr = NULL;
    aphy_txpll_ctrl txpll_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->txpll_ctrl.u32);
    txpll_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    txpll_ctrl.bits.reg_txpll_icp_ictrl = reg_txpll_icp_ictrl;
    hdmi_tx_reg_write(reg_addr, txpll_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_txpll_divsel_loop_set(hi_u32 reg_txpll_divsel_loop)
{
    hi_u32 *reg_addr = NULL;
    aphy_txpll_ctrl txpll_ctrl;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->txpll_ctrl.u32);
    txpll_ctrl.u32 = hdmi_tx_reg_read(reg_addr);
    txpll_ctrl.bits.reg_txpll_divsel_loop = reg_txpll_divsel_loop;
    hdmi_tx_reg_write(reg_addr, txpll_ctrl.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_gc_txpll_test_set(hi_u32 reg_txpll_test)
{
    hi_u32 *reg_addr = NULL;
    aphy_txpll_test txpll_test;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->txpll_test.u32);
    txpll_test.u32 = hdmi_tx_reg_read(reg_addr);
    txpll_test.bits.reg_txpll_test = reg_txpll_test;
    hdmi_tx_reg_write(reg_addr, txpll_test.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_ssc_mode_fb_set(hi_u32 reg_ssc_mode_fb)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_set hdmitx_fbssc;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_set.u32);
    hdmitx_fbssc.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_fbssc.bits.reg_ssc_mode_fb = reg_ssc_mode_fb;
    hdmi_tx_reg_write(reg_addr, hdmitx_fbssc.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_load_fb_set(hi_u32 reg_set_load_fb)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_set hdmitx_fbssc;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_set.u32);
    hdmitx_fbssc.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_fbssc.bits.reg_set_load_fb = reg_set_load_fb;
    hdmi_tx_reg_write(reg_addr, hdmitx_fbssc.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_fb_set(hi_u32 reg_set_fb)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_set hdmitx_fbssc;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_set.u32);
    hdmitx_fbssc.u32 = hdmi_tx_reg_read(reg_addr);
    hdmitx_fbssc.bits.reg_set_fb = reg_set_fb;
    hdmi_tx_reg_write(reg_addr, hdmitx_fbssc.u32);

    return HI_SUCCESS;
}

hi_s32 hdmi_reg_span_fb_set(hi_u32 reg_span_fb)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_step fbssc_step;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_step.u32);
    fbssc_step.u32 = hdmi_tx_reg_read(reg_addr);
    fbssc_step.bits.reg_span_fb = reg_span_fb;
    hdmi_tx_reg_write(reg_addr, fbssc_step.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_span_fb_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_step fbssc_step;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_step.u32);
    fbssc_step.u32 = hdmi_tx_reg_read(reg_addr);
    return fbssc_step.bits.reg_span_fb;
}

hi_s32 hdmi_reg_step_fb_set(hi_u32 reg_step_fb)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_step fbssc_step;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_step.u32);
    fbssc_step.u32 = hdmi_tx_reg_read(reg_addr);
    fbssc_step.bits.reg_step_fb = reg_step_fb;
    hdmi_tx_reg_write(reg_addr, fbssc_step.u32);

    return HI_SUCCESS;
}

hi_u32 hdmi_reg_step_fb_get(hi_void)
{
    hi_u32 *reg_addr = NULL;
    hdmitx_fbssc_step fbssc_step;

    reg_addr = (hi_u32 *)&(g_hdmi2tx_dphy_regs->fb_ssc_step.u32);
    fbssc_step.u32 = hdmi_tx_reg_read(reg_addr);
    return fbssc_step.bits.reg_step_fb;
}

