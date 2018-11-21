/*
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/**
 * DOC: declare public APIs exposed by the mlme component
 */

#ifndef _WLAN_MLME_API_H_
#define _WLAN_MLME_API_H_

#include <wlan_mlme_public_struct.h>
#include <wlan_objmgr_psoc_obj.h>
#include <wlan_cmn.h>
#include "sme_api.h"

/**
 * wlan_mlme_get_cfg_str() - Copy the uint8_t array for a particular CFG
 * @dst:       pointer to the destination buffer.
 * @cfg_str:   pointer to the cfg string structure
 * @len:       length to be copied
 *
 * Return: QDF_STATUS_SUCCESS or QDF_STATUS_E_FAILURE
 */
QDF_STATUS wlan_mlme_get_cfg_str(uint8_t *dst, struct mlme_cfg_str *cfg_str,
				 qdf_size_t *len);

/**
 * wlan_mlme_set_cfg_str() - Set values for a particular CFG
 * @src:            pointer to the source buffer.
 * @dst_cfg_str:    pointer to the cfg string structure to be modified
 * @len:            length to be written
 *
 * Return: QDF_STATUS_SUCCESS or QDF_STATUS_E_FAILURE
 */
QDF_STATUS wlan_mlme_set_cfg_str(uint8_t *src, struct mlme_cfg_str *dst_cfg_str,
				 qdf_size_t len);

/**
 * wlan_mlme_get_edca_params() - get the EDCA parameters corresponding to the
 * edca profile access category
 * @edca_params:   pointer to mlme edca parameters structure
 * @data:          data to which the parameter is to be copied
 * @edca_ac:       edca ac type enum passed to get the cfg value
 *
 * Return QDF_STATUS_SUCCESS or QDF_STATUS_E_FAILURE
 *
 */
QDF_STATUS wlan_mlme_get_edca_params(struct wlan_mlme_edca_params *edca_params,
				     uint8_t *data, enum e_edca_type edca_ac);

/*
 * mlme_get_wep_key() - get the wep key to process during auth frame
 * @wep_params: cfg wep parameters structure
 * @wep_key_id: default key number
 * @default_key: default key to be copied
 * @key_len: length of the key to copy
 *
 * Return QDF_STATUS
 */
QDF_STATUS mlme_get_wep_key(struct wlan_mlme_wep_cfg *wep_params,
			    enum wep_key_id wep_keyid, uint8_t *default_key,
			    qdf_size_t *key_len);

/**
 * mlme_set_wep_key() - set the wep keys during auth
 * @wep_params: cfg wep parametrs structure
 * @wep_key_id: default key number that needs to be copied
 * @key_to_set: destination buffer to be copied
 * @len:        size to be copied
 */
QDF_STATUS mlme_set_wep_key(struct wlan_mlme_wep_cfg *wep_params,
			    enum wep_key_id wep_keyid, uint8_t *key_to_set,
			    qdf_size_t len);
/**
 * wlan_mlme_get_ht_cap_info() - Get the HT cap info config
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_ht_cap_info(struct wlan_objmgr_psoc *psoc,
				     struct mlme_ht_capabilities_info
				     *ht_cap_info);

/**
 * wlan_mlme_get_manufacturer_name() - get manufacturer name
 * @psoc: pointer to psoc object
 * @pbuf: pointer of the buff which will be filled for the caller
 * @plen: pointer of max buffer length
 *        actual length will be returned at this address
 * This function gets manufacturer name
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_mlme_get_manufacturer_name(struct wlan_objmgr_psoc *psoc,
				uint8_t *pbuf, uint32_t *plen);

/**
 * wlan_mlme_get_model_number() - get model number
 * @psoc: pointer to psoc object
 * @pbuf: pointer of the buff which will be filled for the caller
 * @plen: pointer of max buffer length
 *        actual length will be returned at this address
 * This function gets model number
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_mlme_get_model_number(struct wlan_objmgr_psoc *psoc,
			   uint8_t *pbuf, uint32_t *plen);

/**
 * wlan_mlme_get_model_name() - get model name
 * @psoc: pointer to psoc object
 * @pbuf: pointer of the buff which will be filled for the caller
 * @plen: pointer of max buffer length
 *        actual length will be returned at this address
 * This function gets model name
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_mlme_get_model_name(struct wlan_objmgr_psoc *psoc,
			 uint8_t *pbuf, uint32_t *plen);

/**
 * wlan_mlme_get_manufacture_product_name() - get manufacture product name
 * @psoc: pointer to psoc object
 * @pbuf: pointer of the buff which will be filled for the caller
 * @plen: pointer of max buffer length
 *        actual length will be returned at this address
 * This function gets manufacture product name
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_mlme_get_manufacture_product_name(struct wlan_objmgr_psoc *psoc,
				       uint8_t *pbuf, uint32_t *plen);

/**
 * wlan_mlme_get_manufacture_product_version() - get manufacture product version
 * @psoc: pointer to psoc object
 * @pbuf: pointer of the buff which will be filled for the caller
 * @plen: pointer of max buffer length
 *        actual length will be returned at this address
 * This function gets manufacture product version
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_mlme_get_manufacture_product_version(struct wlan_objmgr_psoc *psoc,
					  uint8_t *pbuf, uint32_t *plen);

/**
 * wlan_mlme_set_ht_cap_info() - Set the HT cap info config
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_ht_cap_info(struct wlan_objmgr_psoc *psoc,
				     struct mlme_ht_capabilities_info
				     ht_cap_info);

/**
 * wlan_mlme_get_max_amsdu_num() - get the max amsdu num
 * @psoc: pointer to psoc object
 * @value: pointer to the value where the max_amsdu num is to be filled
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_max_amsdu_num(struct wlan_objmgr_psoc *psoc,
				       uint8_t *value);

/**
 * wlan_mlme_set_max_amsdu_num() - set the max amsdu num
 * @psoc: pointer to psoc object
 * @value: value to be set for max_amsdu_num
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_set_max_amsdu_num(struct wlan_objmgr_psoc *psoc,
				       uint8_t value);

/**
 * wlan_mlme_get_ht_mpdu_density() - get the ht mpdu density
 * @psoc: pointer to psoc object
 * @value: pointer to the value where the ht mpdu density is to be filled
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_ht_mpdu_density(struct wlan_objmgr_psoc *psoc,
					 uint8_t *value);

/**
 * wlan_mlme_set_ht_mpdu_density() - set the ht mpdu density
 * @psoc: pointer to psoc object
 * @value: value to be set for ht mpdu density
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_set_ht_mpdu_density(struct wlan_objmgr_psoc *psoc,
					 uint8_t value);

/**
 * wlan_mlme_get_band_capability() - Get the Band capability config
 * @psoc: pointer to psoc object
 * @band_capability: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_band_capability(struct wlan_objmgr_psoc *psoc,
					 uint8_t *band_capability);

/**
 * wlan_mlme_set_band_capability() - Set the Band capability config
 * @psoc: pointer to psoc object
 * @band_capability: Value to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_band_capability(struct wlan_objmgr_psoc *psoc,
					 uint8_t band_capability);

/**
 * wlan_mlme_get_prevent_link_down() - Get the prevent link down config
 * @psoc: pointer to psoc object
 * @prevent_link_down: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_prevent_link_down(struct wlan_objmgr_psoc *psoc,
					   bool *prevent_link_down);

/**
 * wlan_mlme_get_select_5ghz_margin() - Get the select 5Ghz margin config
 * @psoc: pointer to psoc object
 * @select_5ghz_margin: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_select_5ghz_margin(struct wlan_objmgr_psoc *psoc,
					    uint8_t *select_5ghz_margin);

/**
 * wlan_mlme_get_rtt_mac_randomization() - Get the RTT MAC randomization config
 * @psoc: pointer to psoc object
 * @rtt_mac_randomization: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_rtt_mac_randomization(struct wlan_objmgr_psoc *psoc,
					       bool *rtt_mac_randomization);

/**
 * wlan_mlme_get_crash_inject() - Get the crash inject config
 * @psoc: pointer to psoc object
 * @crash_inject: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_crash_inject(struct wlan_objmgr_psoc *psoc,
				      bool *crash_inject);

/**
 * wlan_mlme_get_lpass_support() - Get the LPASS Support config
 * @psoc: pointer to psoc object
 * @lpass_support: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_lpass_support(struct wlan_objmgr_psoc *psoc,
				       bool *lpass_support);

/**
 * wlan_mlme_get_self_recovery() - Get the self recovery config
 * @psoc: pointer to psoc object
 * @self_recovery: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_self_recovery(struct wlan_objmgr_psoc *psoc,
				       bool *self_recovery);

/**
 * wlan_mlme_get_sub_20_chan_width() - Get the sub 20 chan width config
 * @psoc: pointer to psoc object
 * @sub_20_chan_width: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sub_20_chan_width(struct wlan_objmgr_psoc *psoc,
					   uint8_t *sub_20_chan_width);

/**
 * wlan_mlme_get_fw_timeout_crash() - Get the fw timeout crash config
 * @psoc: pointer to psoc object
 * @fw_timeout_crash: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_fw_timeout_crash(struct wlan_objmgr_psoc *psoc,
					  bool *fw_timeout_crash);

/**
 * wlan_mlme_get_ito_repeat_count() - Get the fw timeout crash config
 * @psoc: pointer to psoc object
 * @ito_repeat_count: Pointer to the variable from caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_ito_repeat_count(struct wlan_objmgr_psoc *psoc,
					  uint8_t *ito_repeat_count);

/**
 * wlan_mlme_get_acs_with_more_param() - Get the acs_with_more_param flag
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_acs_with_more_param(struct wlan_objmgr_psoc *psoc,
					     bool *value);

/**
 * wlan_mlme_get_auto_channel_weight() - Get the auto channel weight
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_auto_channel_weight(struct wlan_objmgr_psoc *psoc,
					     uint32_t *value);

/**
 * wlan_mlme_get_vendor_acs_support() - Get the vendor based channel selece
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */

QDF_STATUS wlan_mlme_get_vendor_acs_support(struct wlan_objmgr_psoc *psoc,
					    bool *value);

/**
 * wlan_mlme_get_acs_support_for_dfs_ltecoex() - Get the flag for
 *						 acs support for dfs ltecoex
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_acs_support_for_dfs_ltecoex(struct wlan_objmgr_psoc *psoc,
					  bool *value);

/**
 * wlan_mlme_get_external_acs_policy() - Get the flag for external acs policy
 *
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_external_acs_policy(struct wlan_objmgr_psoc *psoc,
				  bool *value);

/**
 *
 * wlan_mlme_get_sap_inactivity_override() - Check if sap max inactivity
 * override flag is set.
 * @psoc: pointer to psoc object
 * @sme_config - Sme config struct
 *
 * Return: QDF Status
 */
void wlan_mlme_get_sap_inactivity_override(struct wlan_objmgr_psoc *psoc,
					   bool *value);

/**
 * wlan_mlme_get_ignore_peer_ht_mode() - Get the ignore peer ht opmode flag
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_ignore_peer_ht_mode(struct wlan_objmgr_psoc *psoc,
					bool *value);
/**
 * wlan_mlme_get_tx_chainmask_cck() - Get the tx_chainmask_cfg value
 *
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF_STATUS_FAILURE or QDF_STATUS_SUCCESS
 */
QDF_STATUS wlan_mlme_get_tx_chainmask_cck(struct wlan_objmgr_psoc *psoc,
					  bool *value);

/**
 * wlan_mlme_get_tx_chainmask_1ss() - Get the tx_chainmask_1ss value
 *
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF_STATUS_FAILURE or QDF_STATUS_SUCCESS
 */
QDF_STATUS wlan_mlme_get_tx_chainmask_1ss(struct wlan_objmgr_psoc *psoc,
					  uint8_t *value);

/**
 * wlan_mlme_get_num_11b_tx_chains() -  Get the number of 11b only tx chains
 *
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF_STATUS_FAILURE or QDF_STATUS_SUCCESS
 */
QDF_STATUS wlan_mlme_get_num_11b_tx_chains(struct wlan_objmgr_psoc *psoc,
					   uint16_t *value);

/**
 * wlan_mlme_get_num_11ag_tx_chains() - get the total number of 11a/g tx chains
 *
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF_STATUS_FAILURE or QDF_STATUS_SUCCESS
 */
QDF_STATUS wlan_mlme_get_num_11ag_tx_chains(struct wlan_objmgr_psoc *psoc,
					    uint16_t *value);

/**
 * wlan_mlme_configure_chain_mask() - configure chainmask parameters
 *
 * @psoc: pointer to psoc object
 * @session_id: vdev_id
 *
 * Return: QDF_STATUS_FAILURE or QDF_STATUS_SUCCESS
 */
QDF_STATUS wlan_mlme_configure_chain_mask(struct wlan_objmgr_psoc *psoc,
					  uint8_t session_id);

/**
 * wlan_mlme_set_sap_listen_interval() - Set the sap listen interval
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_sap_listen_interval(struct wlan_objmgr_psoc *psoc,
					     int value);

/**
 * wlan_mlme_set_assoc_sta_limit() - Set the assoc sta limit
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_assoc_sta_limit(struct wlan_objmgr_psoc *psoc,
					 int value);

/**
 * wlan_mlme_set_rmc_action_period_freq() - Set the rmc action period frequency
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_rmc_action_period_freq(struct wlan_objmgr_psoc *psoc,
						int value);

/**
 * wlan_mlme_set_sap_get_peer_info() - get the sap get peer info
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_get_peer_info(struct wlan_objmgr_psoc *psoc,
					   bool *value);

/**
 * wlan_mlme_get_sap_allow_all_channels() - get the value of sap allow all
 * channels
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_allow_all_channels(struct wlan_objmgr_psoc *psoc,
						bool *value);

/**
 * wlan_mlme_get_sap_allow_all_channels() - get the value sap max peers
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_max_peers(struct wlan_objmgr_psoc *psoc,
				       int *value);

/**
 * wlan_mlme_set_sap_max_peers() - set the value sap max peers
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_sap_max_peers(struct wlan_objmgr_psoc *psoc,
				       int value);

/**
 * wlan_mlme_get_sap_max_offload_peers() - get the value sap max offload peers
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_max_offload_peers(struct wlan_objmgr_psoc *psoc,
					       int *value);

/**
 * wlan_mlme_get_sap_max_offload_reorder_buffs() - get the value sap max offload
 * reorder buffs.
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_max_offload_reorder_buffs(struct wlan_objmgr_psoc
						       *psoc, int *value);

/**
 * wlan_mlme_get_sap_chn_switch_bcn_count() - get the value sap max channel
 * switch beacon count
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_chn_switch_bcn_count(struct wlan_objmgr_psoc *psoc,
						  int *value);

/**
 * wlan_mlme_get_sap_chn_switch_mode() - get the sap channel
 * switch mode
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_chn_switch_mode(struct wlan_objmgr_psoc *psoc,
					     bool *value);

/**
 * wlan_mlme_get_sap_internal_restart() - get the sap internal
 * restart
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_internal_restart(struct wlan_objmgr_psoc *psoc,
					      bool *value);
/**
 * wlan_mlme_get_sap_max_modulated_dtim() - get the max modulated dtim
 * restart
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_max_modulated_dtim(struct wlan_objmgr_psoc *psoc,
						uint8_t *value);

/**
 * wlan_mlme_get_sap_chan_pref_location() - get the sap chan pref location
 * restart
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_chan_pref_location(struct wlan_objmgr_psoc *psoc,
						uint8_t *value);

/**
 * wlan_mlme_get_sap_country_priority() - get the sap country code priority
 * restart
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_country_priority(struct wlan_objmgr_psoc *psoc,
					      bool *value);

/**
 * wlan_mlme_get_sap_reduced_beacon_interval() - get the sap reduced
 * beacon interval
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_reduced_beacon_interval(struct wlan_objmgr_psoc
						     *psoc, int *value);

/**
 * wlan_mlme_get_sap_chan_switch_rate_enabled() - get the sap rate hostapd
 * enabled beacon interval
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_sap_chan_switch_rate_enabled(struct wlan_objmgr_psoc
						      *psoc, bool *value);

/**
 * wlan_mlme_get_oce_sta_enabled_info() - Get the OCE feature enable
 * info for STA
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_oce_sta_enabled_info(struct wlan_objmgr_psoc *psoc,
					      bool *value);

/**
 * wlan_mlme_get_oce_sap_enabled_info() - Get the OCE feature enable
 * info for SAP
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_oce_sap_enabled_info(struct wlan_objmgr_psoc *psoc,
					      bool *value);

#ifdef WLAN_FEATURE_11AX
/**
 * wlan_mlme_cfg_get_he_ul_mumimo() - Get the HE Ul Mumio
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_cfg_get_he_ul_mumimo(struct wlan_objmgr_psoc *psoc,
					  uint32_t *value);

/**
 * wlan_mlme_cfg_set_he_ul_mumimo() - Set the HE Ul Mumio
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_cfg_set_he_ul_mumimo(struct wlan_objmgr_psoc *psoc,
					  uint32_t value);

/**
 * wlan_mlme_cfg_get_enable_ul_mimo() - Get the HE Ul mimo
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_cfg_get_enable_ul_mimo(struct wlan_objmgr_psoc *psoc,
					    uint8_t *value);

/**
 * wlan_mlme_cfg_get_enable_ul_ofdm() - Get enable ul ofdm
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_cfg_get_enable_ul_ofdm(struct wlan_objmgr_psoc *psoc,
					    uint8_t *value);

/**
 * mlme_update_tgt_he_caps_in_cfg() - Update tgt he cap in mlme component
 *
 * @psoc: pointer to psoc object
 * @cfg: pointer to config params from target
 *
 * This api to be used by callers to update
 * he caps in mlme.
 *
 * Return: QDF_STATUS_SUCCESS or QDF_STATUS_FAILURE
 */
QDF_STATUS mlme_update_tgt_he_caps_in_cfg(struct wlan_objmgr_psoc *psoc,
					  struct wma_tgt_cfg *cfg);
#endif

/**
 * wlan_mlme_get_rts_threshold() - Get the RTS threshold config
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_rts_threshold(struct wlan_objmgr_psoc *psoc,
				       uint32_t *value);

/**
 * wlan_mlme_set_rts_threshold() - Set the RTS threshold config
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_rts_threshold(struct wlan_objmgr_psoc *psoc,
				       uint32_t value);

/**
 * wlan_mlme_get_frag_threshold() - Get the Fragmentation threshold
 *                                  config
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_frag_threshold(struct wlan_objmgr_psoc *psoc,
					uint32_t *value);

/**
 * wlan_mlme_set_frag_threshold() - Set the Fragmentation threshold
 *                                  config
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_frag_threshold(struct wlan_objmgr_psoc *psoc,
					uint32_t value);

/**
 * wlan_mlme_get_fils_enabled_info() - Get the fils enable info for driver
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_fils_enabled_info(struct wlan_objmgr_psoc *psoc,
					   bool *value);
/**
 * wlan_mlme_set_fils_enabled_info() - Set the fils enable info for driver
 * @psoc: pointer to psoc object
 * @value: value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_fils_enabled_info(struct wlan_objmgr_psoc *psoc,
					   bool value);

/**
 * wlan_mlme_get_wmm_dir_ac_vi() - Get TSPEC direction
 * for VI
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_dir_ac_vi(struct wlan_objmgr_psoc *psoc,
			    uint8_t *value);

/**
 * wlan_mlme_get_wmm_nom_msdu_size_ac_vi() - Get normal
 * MSDU size for VI
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_nom_msdu_size_ac_vi(struct wlan_objmgr_psoc *psoc,
				      uint16_t *value);

/**
 * wlan_mlme_get_wmm_mean_data_rate_ac_vi() - mean data
 * rate for VI
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_mean_data_rate_ac_vi(struct wlan_objmgr_psoc *psoc,
				       uint32_t *value);

/**
 * wlan_mlme_get_wmm_min_phy_rate_ac_vi() - min PHY
 * rate for VI
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_min_phy_rate_ac_vi(struct wlan_objmgr_psoc *psoc,
				     uint32_t *value);

/**
 * wlan_mlme_get_wmm_sba_ac_vi() - surplus bandwidth
 * allowance for VI
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_sba_ac_vi(struct wlan_objmgr_psoc *psoc, uint16_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_vi_srv_intv() - Get Uapsd service
 * interval for video
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_vi_srv_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_vi_sus_intv() - Get Uapsd suspension
 * interval for video
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_vi_sus_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_get_wmm_dir_ac_be() - Get TSPEC direction
 * for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_dir_ac_be(struct wlan_objmgr_psoc *psoc,
			    uint8_t *value);

/**
 * wlan_mlme_get_wmm_nom_msdu_size_ac_be() - Get normal
 * MSDU size for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_nom_msdu_size_ac_be(struct wlan_objmgr_psoc *psoc,
				      uint16_t *value);

/**
 * wlan_mlme_get_wmm_mean_data_rate_ac_be() - mean data
 * rate for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_mean_data_rate_ac_be(struct wlan_objmgr_psoc *psoc,
				       uint32_t *value);

/**
 * wlan_mlme_get_wmm_min_phy_rate_ac_be() - min PHY
 * rate for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_wmm_min_phy_rate_ac_be(struct wlan_objmgr_psoc *psoc,
						uint32_t *value);

/**
 * wlan_mlme_get_wmm_sba_ac_be() - surplus bandwidth
 * allowance for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_wmm_sba_ac_be(struct wlan_objmgr_psoc *psoc,
				       uint16_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_be_srv_intv() - Get Uapsd service
 * interval for BE
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_wmm_uapsd_be_srv_intv(struct wlan_objmgr_psoc *psoc,
					       uint32_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_be_sus_intv() - Get Uapsd suspension
 * interval for BE
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_wmm_uapsd_be_sus_intv(struct wlan_objmgr_psoc *psoc,
					       uint32_t *value);

/**
 * wlan_mlme_get_wmm_dir_ac_bk() - Get TSPEC direction
 * for BK
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_dir_ac_bk(struct wlan_objmgr_psoc *psoc, uint8_t *value);

/**
 * wlan_mlme_get_wmm_nom_msdu_size_ac_bk() - Get normal
 * MSDU size for BK
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_nom_msdu_size_ac_bk(struct wlan_objmgr_psoc *psoc,
				      uint16_t *value);

/**
 * wlan_mlme_get_wmm_mean_data_rate_ac_bk() - mean data
 * rate for BK
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_mean_data_rate_ac_bk(struct wlan_objmgr_psoc *psoc,
				       uint32_t *value);

/**
 * wlan_mlme_get_wmm_min_phy_rate_ac_bk() - min PHY
 * rate for BK
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_min_phy_rate_ac_bk(struct wlan_objmgr_psoc *psoc,
				     uint32_t *value);

/**
 * wlan_mlme_get_wmm_sba_ac_bk() - surplus bandwidth
 * allowance for BE
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_sba_ac_bk(struct wlan_objmgr_psoc *psoc, uint16_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_bk_srv_intv() - Get Uapsd service
 * interval for BK
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_bk_srv_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_bk_sus_intv() - Get Uapsd suspension
 * interval for BK
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_bk_sus_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_get_wmm_mode() - Enable WMM feature
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_mode(struct wlan_objmgr_psoc *psoc, uint8_t *value);

/**
 * wlan_mlme_get_80211e_is_enabled() - Enable 802.11e feature
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_80211e_is_enabled(struct wlan_objmgr_psoc *psoc, bool *value);

/**
 * wlan_mlme_get_wmm_uapsd_mask() - setup U-APSD mask for ACs
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_mask(struct wlan_objmgr_psoc *psoc, uint8_t *value);

/**
 * wlan_mlme_get_implicit_qos_is_enabled() - Enable implicit QOS
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_implicit_qos_is_enabled(struct wlan_objmgr_psoc *psoc,
				      bool *value);

/**
 * wlan_mlme_get_wmm_dir_ac_vo() - Get TSPEC direction
 * for VO
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_get_wmm_dir_ac_vo(struct wlan_objmgr_psoc *psoc,
				       uint8_t *value);

/**
 * wlan_mlme_get_wmm_nom_msdu_size_ac_vo() - Get normal
 * MSDU size for VO
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_nom_msdu_size_ac_vo(struct wlan_objmgr_psoc *psoc,
				      uint16_t *value);

/**
 * wlan_mlme_get_wmm_mean_data_rate_ac_vo() - mean data rate for VO
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_mean_data_rate_ac_vo(struct wlan_objmgr_psoc *psoc,
				       uint32_t *value);
/**
 * wlan_mlme_get_wmm_min_phy_rate_ac_vo() - min PHY
 * rate for VO
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_min_phy_rate_ac_vo(struct wlan_objmgr_psoc *psoc,
				     uint32_t *value);
/**
 * wlan_mlme_get_wmm_sba_ac_vo() - surplus bandwidth allowance for VO
 * @psoc: pointer to psoc object
 * @value: Value that needs to be set from the caller
 *
 *  Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_sba_ac_vo(struct wlan_objmgr_psoc *psoc, uint16_t *value);

/**
 * wlan_mlme_set_enable_bcast_probe_rsp() - Set enable bcast probe resp info
 * @psoc: pointer to psoc object
 * @value: value that needs to be set from the caller
 *
 * Return: QDF Status
 */
QDF_STATUS wlan_mlme_set_enable_bcast_probe_rsp(struct wlan_objmgr_psoc *psoc,
						bool value);

/**
 * wlan_mlme_get_wmm_uapsd_vo_srv_intv() - Get Uapsd service
 * interval for voice
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_vo_srv_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_get_wmm_uapsd_vo_sus_intv() - Get Uapsd suspension
 * interval for voice
 * @psoc: pointer to psoc object
 * @value: pointer to the value which will be filled for the caller
 *
 * Return: QDF Status
 */
QDF_STATUS
wlan_mlme_get_wmm_uapsd_vo_sus_intv(struct wlan_objmgr_psoc *psoc,
				    uint32_t *value);

/**
 * wlan_mlme_cfg_get_vht_max_mpdu_len() - gets vht max mpdu length from cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_max_mpdu_len(struct wlan_objmgr_psoc *psoc,
					      uint8_t *value);

/**
 * wlan_mlme_cfg_set_vht_max_mpdu_len() - sets vht max mpdu length into cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_max_mpdu_len(struct wlan_objmgr_psoc *psoc,
					      uint8_t value);

/**
 * wlan_mlme_cfg_get_vht_chan_width() - gets vht supported channel width from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_chan_width(struct wlan_objmgr_psoc *psoc,
					    uint8_t *value);

/**
 * wlan_mlme_cfg_set_vht_chan_width() - sets vht supported channel width into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_chan_width(struct wlan_objmgr_psoc *psoc,
					    uint8_t value);

/**
 * wlan_mlme_cfg_get_vht_chan_width() - sets vht supported channel width into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_chan_width(struct wlan_objmgr_psoc *psoc,
					    uint8_t *value);

/**
 * wlan_mlme_cfg_get_vht_ldpc_coding_cap() - gets vht ldpc coding cap from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_ldpc_coding_cap(struct wlan_objmgr_psoc *psoc,
						 bool *value);

/**
 * wlan_mlme_cfg_set_vht_ldpc_coding_cap() - sets vht ldpc coding cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_ldpc_coding_cap(struct wlan_objmgr_psoc *psoc,
					         bool value);

/**
 * wlan_mlme_cfg_get_vht_short_gi_80mhz() - gets vht short gi 80MHz from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_short_gi_80mhz(struct wlan_objmgr_psoc *psoc,
					        bool *value);

/**
 * wlan_mlme_cfg_set_vht_short_gi_80mhz() - sets vht short gi 80MHz into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_short_gi_80mhz(struct wlan_objmgr_psoc *psoc,
					        bool value);

/**
 * wlan_mlme_cfg_get_short_gi_160_mhz() - gets vht short gi 160MHz from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_short_gi_160_mhz(struct wlan_objmgr_psoc *psoc,
					      bool *value);

/**
 * wlan_mlme_cfg_set_short_gi_160_mhz() - sets vht short gi 160MHz into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_short_gi_160_mhz(struct wlan_objmgr_psoc *psoc,
					      bool value);

/**
 * wlan_mlme_cfg_get_vht_tx_stbc() - gets vht tx stbc from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_tx_stbc(struct wlan_objmgr_psoc *psoc,
				         bool *value);

/**
 * wlan_mlme_cfg_get_vht_rx_stbc() - gets vht rx stbc from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_rx_stbc(struct wlan_objmgr_psoc *psoc,
				         bool *value);

/**
 * wlan_mlme_cfg_set_vht_tx_stbc() - sets vht tx stbc into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_tx_stbc(struct wlan_objmgr_psoc *psoc,
				         bool value);

/**
 * wlan_mlme_cfg_get_vht_rx_stbc() - gets vht rx stbc from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_rx_stbc(struct wlan_objmgr_psoc *psoc,
				         bool *value);

/**
 * wlan_mlme_cfg_set_vht_rx_stbc() - sets vht rx stbc into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_rx_stbc(struct wlan_objmgr_psoc *psoc,
				         bool value);

/**
 * wlan_mlme_cfg_get_vht_su_bformer() - gets vht su beam former cap from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_su_bformer(struct wlan_objmgr_psoc *psoc,
				            bool *value);

/**
 * wlan_mlme_cfg_set_vht_su_bformer() - sets vht su beam former cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_su_bformer(struct wlan_objmgr_psoc *psoc,
				            bool value);

/**
 * wlan_mlme_cfg_set_vht_su_bformee() - sets vht su beam formee cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_su_bformee(struct wlan_objmgr_psoc *psoc,
				            bool value);

/**
 * wlan_mlme_cfg_set_vht_tx_bfee_ant_supp() - sets vht Beamformee antenna
 * support cap
 * into cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_tx_bfee_ant_supp(struct wlan_objmgr_psoc *psoc,
					           uint8_t value);

/**
 * wlan_mlme_cfg_get_vht_tx_bfee_ant_supp() - Gets vht Beamformee antenna
 * support cap into cfg item
 *
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_tx_bfee_ant_supp(struct wlan_objmgr_psoc *psoc,
						  uint8_t *value);

/**
 * wlan_mlme_cfg_set_vht_num_sounding_dim() - sets vht no of sounding dimensions
 * into cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_num_sounding_dim(struct wlan_objmgr_psoc *psoc,
					          uint8_t value);

/**
 * wlan_mlme_cfg_get_vht_mu_bformer() - gets vht mu beam former cap from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_mu_bformer(struct wlan_objmgr_psoc *psoc,
				            bool *value);

/**
 * wlan_mlme_cfg_set_vht_mu_bformer() - sets vht mu beam former cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_mu_bformer(struct wlan_objmgr_psoc *psoc,
				            bool value);

/**
 * wlan_mlme_cfg_get_vht_mu_bformee() - gets vht mu beam formee cap from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_mu_bformee(struct wlan_objmgr_psoc *psoc,
				            bool *value);

/**
 * wlan_mlme_cfg_set_vht_mu_bformee() - sets vht mu beam formee cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_mu_bformee(struct wlan_objmgr_psoc *psoc,
				            bool value);

/**
 * wlan_mlme_cfg_get_vht_txop_ps() - gets vht tx ops ps cap from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_txop_ps(struct wlan_objmgr_psoc *psoc,
				         bool *value);

/**
 * wlan_mlme_cfg_set_vht_txop_ps() - sets vht tx ops ps cap into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_txop_ps(struct wlan_objmgr_psoc *psoc,
				         bool value);

/**
 * wlan_mlme_cfg_get_vht_ampdu_len_exp() - gets vht max AMPDU length exponent from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_ampdu_len_exp(struct wlan_objmgr_psoc *psoc,
					       uint8_t *value);

/**
 * wlan_mlme_cfg_set_vht_ampdu_len_exp() - sets vht max AMPDU length exponent into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_ampdu_len_exp(struct wlan_objmgr_psoc *psoc,
					       uint8_t value);

/**
 * wlan_mlme_cfg_get_vht_rx_mcs_map() - gets vht rx mcs map from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_rx_mcs_map(struct wlan_objmgr_psoc *psoc,
				            uint32_t *value);

/**
 * wlan_mlme_cfg_set_vht_rx_mcs_map() - sets rx mcs map into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_rx_mcs_map(struct wlan_objmgr_psoc *psoc,
				            uint32_t value);

/**
 * wlan_mlme_cfg_get_vht_tx_mcs_map() - gets vht tx mcs map from
 * cfg item
 * @psoc: psoc context
 * @value: pointer to get required data
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_tx_mcs_map(struct wlan_objmgr_psoc *psoc,
				            uint32_t *value);

/**
 * wlan_mlme_cfg_set_vht_tx_mcs_map() - sets tx mcs map into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_tx_mcs_map(struct wlan_objmgr_psoc *psoc,
				            uint32_t value);

/**
 * wlan_mlme_cfg_set_vht_rx_supp_data_rate() - sets rx supported data rate into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
wlan_mlme_cfg_set_vht_rx_supp_data_rate(struct wlan_objmgr_psoc *psoc,
					uint32_t value);

/**
 * wlan_mlme_cfg_set_vht_tx_supp_data_rate() - sets tx supported data rate into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
wlan_mlme_cfg_set_vht_tx_supp_data_rate(struct wlan_objmgr_psoc *psoc,
					uint32_t value);

/**
 * wlan_mlme_cfg_get_vht_basic_mcs_set() - gets basic mcs set from
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_get_vht_basic_mcs_set(struct wlan_objmgr_psoc *psoc,
					       uint32_t *value);

/**
 * wlan_mlme_cfg_set_vht_basic_mcs_set() - sets basic mcs set into
 * cfg item
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_cfg_set_vht_basic_mcs_set(struct wlan_objmgr_psoc *psoc,
					       uint32_t value);

/**
 * wlan_mlme_get_vht_enable_tx_bf() - Get vht enable tx bf
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_enable_tx_bf(struct wlan_objmgr_psoc *psoc,
					  bool *value);

/**
 * wlan_mlme_get_vht_tx_su_beamformer() - VHT enable tx su beamformer
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_tx_su_beamformer(struct wlan_objmgr_psoc *psoc,
					      bool *value);

/**
 * wlan_mlme_get_vht_channel_width() - gets Channel width capability
 * for 11ac
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_channel_width(struct wlan_objmgr_psoc *psoc,
				           uint8_t *value);

/**
 * wlan_mlme_get_vht_rx_mcs_8_9() - VHT Rx MCS capability for 1x1 mode
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_rx_mcs_8_9(struct wlan_objmgr_psoc *psoc,
					uint8_t *value);

/**
 * wlan_mlme_get_vht_tx_mcs_8_9() - VHT Tx MCS capability for 1x1 mode
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_tx_mcs_8_9(struct wlan_objmgr_psoc *psoc,
				        uint8_t *value);

/**
 * wlan_mlme_get_vht_rx_mcs_2x2() - VHT Rx MCS capability for 2x2 mode
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_rx_mcs_2x2(struct wlan_objmgr_psoc *psoc,
					uint8_t *value);

/**
 * wlan_mlme_get_vht_tx_mcs_2x2() - VHT Tx MCS capability for 2x2 mode
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_tx_mcs_2x2(struct wlan_objmgr_psoc *psoc,
					uint8_t *value);

/**
 * wlan_mlme_get_vht20_mcs9() - Enables VHT MCS9 in 20M BW operation
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht20_mcs9(struct wlan_objmgr_psoc *psoc,
				    bool *value);

/**
 * wlan_mlme_get_vht_enable2x2() - Enables/disables VHT Tx/Rx MCS values for 2x2
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_enable2x2(struct wlan_objmgr_psoc *psoc,
				       bool *value);

/**
 * wlan_mlme_set_vht_enable2x2() - Enables/disables VHT Tx/Rx MCS values for 2x2
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_set_vht_enable2x2(struct wlan_objmgr_psoc *psoc,
				       bool value);

/**
 * wlan_mlme_get_vht_enable_paid() - Enables/disables paid feature
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_enable_paid(struct wlan_objmgr_psoc *psoc,
					 bool *value);

/**
 * wlan_mlme_get_vht_enable_gid() - Enables/disables VHT GID feature
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_enable_gid(struct wlan_objmgr_psoc *psoc,
					bool *value);

/**
 * wlan_mlme_get_vht_for_24ghz() - Enables/disables VHT for 24 ghz
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vht_for_24ghz(struct wlan_objmgr_psoc *psoc,
				       bool *value);

/**
 * wlan_mlme_get_vendor_vht_for_24ghz() - nables/disables vendor VHT for 24 ghz
 * @psoc: psoc context
 * @value: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_mlme_get_vendor_vht_for_24ghz(struct wlan_objmgr_psoc *psoc,
					      bool *value);

/**
 * mlme_update_vht_cap() - update vht capabilities
 * @psoc: psoc context
 * @cfg: data to be set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_update_vht_cap(struct wlan_objmgr_psoc *psoc,
			       struct wma_tgt_vht_cap *cfg);

/**
 * mlme_update_nss_vht_cap() - Update the number of spatial
 * streams supported for vht
 * @psoc: psoc context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_update_nss_vht_cap(struct wlan_objmgr_psoc *psoc);

#endif /* _WLAN_MLME_API_H_ */
